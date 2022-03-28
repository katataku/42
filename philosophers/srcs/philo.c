/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:52:19 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/29 08:14:24 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_philosopher	*philo)
{
	long long		t_right_fork;
	long long		t_left_fork;

	pthread_mutex_lock(&(philo->ptr_rules->forks[philo->right_fork_id]));
	t_right_fork = get_timestamp();
	write_message(philo, t_right_fork, philo->id, "has taken a fork");
	pthread_mutex_lock(&(philo->ptr_rules->forks[philo->left_fork_id]));
	t_left_fork = get_timestamp();
	pthread_mutex_lock(&(philo->mutex_t_last_meal));
	philo->t_last_meal = t_left_fork;
	pthread_mutex_unlock(&(philo->mutex_t_last_meal));
	write_message(philo, t_left_fork, philo->id, "has taken a fork");
	write_message(philo, philo->t_last_meal, philo->id, "is eating");
	while (get_timestamp() - philo->t_last_meal < philo->ptr_rules->time_to_eat)
		usleep(500);
}

static void	philo_sleep(t_philosopher	*philo)
{
	pthread_mutex_unlock(&(philo->ptr_rules->forks[philo->right_fork_id]));
	pthread_mutex_unlock(&(philo->ptr_rules->forks[philo->left_fork_id]));
	pthread_mutex_lock(&(philo->mutex_x_ate));
	philo->x_ate++;
	pthread_mutex_unlock(&(philo->mutex_x_ate));
	write_message(philo, get_timestamp(), philo->id, "is sleeping");
	while (1)
	{
		pthread_mutex_lock(&(philo->mutex_t_last_meal));
		if (get_timestamp() - philo->t_last_meal >= \
			philo->ptr_rules->time_to_eat + philo->ptr_rules->time_to_sleep)
		{
			pthread_mutex_unlock(&(philo->mutex_t_last_meal));
			break ;
		}
		pthread_mutex_unlock(&(philo->mutex_t_last_meal));
		usleep(500);
	}
}

void	*philo(void *arg)
{
	t_philosopher	*philo;

	philo = arg;
	pthread_mutex_lock(&(philo->mutex_t_last_meal));
	philo->t_last_meal = get_timestamp();
	pthread_mutex_unlock(&(philo->mutex_t_last_meal));
	if (philo->id % 2 != 0)
		usleep(2000);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		write_message(philo, get_timestamp(), philo->id, "is thinking");
	}
	return (NULL);
}
