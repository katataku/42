/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:52:19 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/27 10:01:57 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_PHILO 250

struct	s_rules;

typedef struct s_philosopher
{
	int					id;
	int					x_ate;
	pthread_mutex_t		mutex_x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	pthread_mutex_t		mutex_t_last_meal;
	struct s_rules		*ptr_rules;
}						t_philosopher;


typedef struct s_rules
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_times_each_philosopher_must_eat;
	int					nb_eat;
	int					dieded;
	pthread_mutex_t		mutex_dieded;
	int					x_all_ate_philos;
	pthread_mutex_t		mutex_x_all_ate_philos;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[MAX_PHILO];
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
	long long		t_right_fork;
	long long		t_left_fork;

	philo = arg;
	pthread_mutex_lock(&(philo->mutex_t_last_meal));
	philo->t_last_meal = get_timestamp();
	pthread_mutex_unlock(&(philo->mutex_t_last_meal));
	if (philo->id % 2 != 0)
		usleep(2000);
	while (1)
	{
		while (pthread_mutex_lock(&(philo->ptr_rules->forks[philo->right_fork_id])) != 0)
			continue ;
		t_right_fork = get_timestamp();
		while (pthread_mutex_lock(&(philo->ptr_rules->forks[philo->left_fork_id])) != 0)
			continue ;
		t_left_fork = get_timestamp();
	//eat
		pthread_mutex_lock(&(philo->mutex_t_last_meal));
		philo->t_last_meal = t_left_fork;
		pthread_mutex_unlock(&(philo->mutex_t_last_meal));
		printf("%lld %d has taken a fork\n", t_right_fork, philo->id);
		printf("%lld %d has taken a fork\n", t_left_fork, philo->id);
		printf("%lld %d is eating\n", philo->t_last_meal, philo->id);
		while (get_timestamp() - philo->t_last_meal < philo->ptr_rules->time_to_eat)
			usleep(500);
	//forks back
		pthread_mutex_unlock(&(philo->ptr_rules->forks[philo->right_fork_id]));
		pthread_mutex_unlock(&(philo->ptr_rules->forks[philo->left_fork_id]));
		pthread_mutex_lock(&(philo->mutex_x_ate));
		philo->x_ate++;
		pthread_mutex_unlock(&(philo->mutex_x_ate));

	//sleep
		printf("%lld %d is sleeping\n", get_timestamp(), philo->id);
		while (1)
		{
			pthread_mutex_lock(&(philo->mutex_t_last_meal));
			if (get_timestamp() - philo->t_last_meal >= philo->ptr_rules->time_to_eat + philo->ptr_rules->time_to_sleep)
			{
				pthread_mutex_unlock(&(philo->mutex_t_last_meal));
				break ;
			}
			pthread_mutex_unlock(&(philo->mutex_t_last_meal));
			usleep(500);
		}
	}
	return (NULL);
}


void	*monitor(void *arg)
{
	long long		timestamp;
	t_philosopher	*philo;
	bool			is_ate;

	philo = arg;
	is_ate = false;
	while (1)
	{
		timestamp = get_timestamp();
		pthread_mutex_lock(&(philo->mutex_t_last_meal));
		if (timestamp - philo->t_last_meal > philo->ptr_rules->time_to_die)
		{
			pthread_mutex_lock(&(philo->ptr_rules->mutex_dieded));
			philo->ptr_rules->dieded++;
			pthread_mutex_unlock(&(philo->ptr_rules->mutex_dieded));
			printf("%lld %d died\n", timestamp, philo->id);
			break ;
		}
		pthread_mutex_unlock(&(philo->mutex_t_last_meal));

		if (! is_ate)
		{
			pthread_mutex_lock(&(philo->mutex_x_ate));
			if (philo->x_ate > philo->ptr_rules->nb_of_times_each_philosopher_must_eat)
			{
				pthread_mutex_lock(&(philo->ptr_rules->mutex_x_all_ate_philos));
				philo->ptr_rules->x_all_ate_philos++;
				pthread_mutex_unlock(&(philo->ptr_rules->mutex_x_all_ate_philos));
				is_ate = true;
			}
			pthread_mutex_unlock(&(philo->mutex_x_ate));
		}
		usleep(5000 * 1);
	}
	return (NULL);
}

void	init_rule(t_rules *rule, int argc, char **argv)
{
	rule->nb_philo = ft_atoi(argv[1]);
	rule->time_to_die = ft_atoi(argv[2]);
	rule->time_to_eat = ft_atoi(argv[3]);
	rule->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rule->nb_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		rule->nb_of_times_each_philosopher_must_eat = INT_MAX;
	rule->dieded = 0;
	rule->x_all_ate_philos = 0;
	pthread_mutex_init(&(rule->mutex_dieded), NULL);
	pthread_mutex_init(&(rule->mutex_x_all_ate_philos), NULL);
	for (int i = 0; i < rule->nb_philo; i++)
	{
		pthread_mutex_init(&rule->forks[i], NULL);
	}
}

int	main(int argc, char **argv)
{
	pthread_t		thread;
	t_rules			rule;

	init_rule(&rule, argc, argv);
	for (int i = 0; i <rule.nb_philo; i++)
	{
		pthread_mutex_init(&(rule.philosophers[i].mutex_t_last_meal), NULL);
		pthread_mutex_init(&(rule.philosophers[i].mutex_x_ate), NULL);
		rule.philosophers[i].id = i;
		rule.philosophers[i].x_ate = 0;
		rule.philosophers[i].ptr_rules = &rule;
		rule.philosophers[i].right_fork_id = rule.philosophers[i].id;
		rule.philosophers[i].left_fork_id = (rule.philosophers[i].id + 1) % rule.nb_philo;
		rule.philosophers[i].t_last_meal = LLONG_MAX;
	}
	for (int i = 0; i <rule.nb_philo; i++)
	{
		if (pthread_create(&thread, NULL, monitor, &rule.philosophers[i]) != 0)
			return (0);
		pthread_detach(thread);
	}

	for (int i = 0; i <rule.nb_philo / 2; i = i + 2)
	{
		if (pthread_create(&thread, NULL, philo, &rule.philosophers[i]) != 0)
			return (0);
		pthread_detach(thread);
		if (i != rule.nb_philo - i - 2)
		{
			if (pthread_create(&thread, NULL, philo, &rule.philosophers[rule.nb_philo - i - 2]) != 0)
				return (0);
			pthread_detach(thread);
		}
	}
	for (int i = 1; i <rule.nb_philo; i = i + 2)
	{
		if (pthread_create(&thread, NULL, philo, &rule.philosophers[i]) != 0)
			return (0);
		pthread_detach(thread);
	}

	while (rule.dieded == 0 && rule.x_all_ate_philos < rule.nb_philo)
		continue ;
}
