/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:42:14 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/29 14:14:58 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# define MAX_PHILO 250

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
	pthread_mutex_t		mutex_finish_pgm;
	pthread_mutex_t		mutex_writing;
	t_philosopher		philo[MAX_PHILO];
}						t_rules;

int			ft_atoi(const char *str);
void		init_rule(t_rules *rule, int argc, char **argv);
void		init_philo(t_rules *rule);
void		*philo(void *arg);
void		*monitor(void *arg);
long long	get_timestamp(void);
void		write_message(t_philosopher *philo, int id, char *msg);

#endif
