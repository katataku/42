/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:52:19 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/25 17:39:50 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/time.h>
#include <pthread.h>

#define MAX_PHILO 250
struct s_rules;

typedef	struct			s_philosopher
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_rules		*ptr_rules;
}						t_philosopher;


typedef struct			s_rules
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_times_each_philosopher_must_eat;
	int					nb_eat;
	int					dieded;
	int					all_ate;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[MAX_PHILO];
	pthread_mutex_t		writing;
	t_philosopher		philosophers[MAX_PHILO];
}						t_rules;

long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);

}

void	*philo(void *arg)
{
	t_philosopher	*philo;

	philo = arg;
	printf("%lld %d start\n", get_timestamp(), philo->id);
	while (1)
	{
		while (pthread_mutex_lock(&(philo->ptr_rules->forks[(philo->id+1) % philo->ptr_rules->nb_philo])) != 0)
			usleep(10);
		printf("%lld %d has taken a fork %d \n", get_timestamp(), philo->id,(philo->id+1) % philo->ptr_rules->nb_philo);
		while (pthread_mutex_lock(&(philo->ptr_rules->forks[philo->id])) != 0)
		{
			if (philo->id % 2 == 0)
				usleep(10);
		}
		printf("%lld %d has taken a fork %d \n", get_timestamp(), philo->id,philo->id);
	//eat
		printf("%lld %d is eating\n", get_timestamp(), philo->id);
		usleep(philo->ptr_rules->time_to_eat * 1000);
		philo->t_last_meal = get_timestamp();
	//forks back
		pthread_mutex_unlock(&(philo->ptr_rules->forks[philo->id ]));
		pthread_mutex_unlock(&(philo->ptr_rules->forks[((philo->id)+1) % philo->ptr_rules->nb_philo]));
	//sleep
		printf("%lld %d is sleeping\n", get_timestamp(), philo->id);
		usleep(philo->ptr_rules->time_to_sleep * 1000);
	}
	return (NULL);
}


void	*monitor(void *arg)
{
	long long	timestamp;
	t_philosopher	*philo;

	philo = arg;
	while (1)
	{
		timestamp = get_timestamp();
		if (timestamp - philo->t_last_meal > philo->ptr_rules->time_to_die)
		{
			printf("%lld %d died\n", get_timestamp(), philo->id);
			exit(0);
		}
		usleep(1000*5);
	}
	return (NULL);
}


int	main(int argc, char **argv)
{
	pthread_t		thread;
	t_rules			rule;
	
	(void)argc;
	rule.nb_philo = ft_atoi(argv[1]);
	rule.time_to_die = ft_atoi(argv[2]);
	rule.time_to_eat = ft_atoi(argv[3]);
	rule.time_to_sleep = ft_atoi(argv[4]);
	for (int i = 0; i < rule.nb_philo; i++)
	{
		pthread_mutex_init(&rule.forks[i],NULL);
	}
	for (int i = 0; i <rule.nb_philo; i++)
	{
		rule.philosophers[i].id = i;
		rule.philosophers[i].t_last_meal = get_timestamp();
		rule.philosophers[i].ptr_rules = &rule;
		if (pthread_create(&thread, NULL, philo, &rule.philosophers[i]) != 0)
			return (0);
		pthread_detach(thread);
		if (pthread_create(&thread, NULL, monitor, &rule.philosophers[i]) != 0)
			return (0);
		pthread_detach(thread);
	}
	while (1)
		continue ;
}
