/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:52:19 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/29 07:53:01 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_rule(t_rules *rule, int argc, char **argv)
{
	int	i;

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
	pthread_mutex_init(&(rule->mutex_finish_pgm), NULL);
	pthread_mutex_init(&(rule->mutex_writing), NULL);
	pthread_mutex_lock(&(rule->mutex_finish_pgm));
	i = 0;
	while (i < rule->nb_philo)
		pthread_mutex_init(&rule->forks[i++], NULL);
}

void	init_philo(t_rules *rule)
{
	int	i;

	i = 0;
	while (i < rule->nb_philo)
	{
		pthread_mutex_init(&(rule->philo[i].mutex_t_last_meal), NULL);
		pthread_mutex_init(&(rule->philo[i].mutex_x_ate), NULL);
		rule->philo[i].id = i;
		rule->philo[i].x_ate = 0;
		rule->philo[i].ptr_rules = rule;
		rule->philo[i].right_fork_id = rule->philo[i].id;
		rule->philo[i].left_fork_id = \
			(rule->philo[i].id + 1) % rule->nb_philo;
		rule->philo[i].t_last_meal = LLONG_MAX;
		i++;
	}
}
