/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:52:19 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/29 15:13:40 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_philosopher	*philo)
{
	long long		t_left_fork;
	t_rules			*rule;

	rule = philo->ptr_rules;
	pthread_mutex_lock(&(rule->forks[philo->right_fork_id]));
	write_message(philo, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rule->forks[philo->left_fork_id]));
	write_message(philo, philo->id, "has taken a fork");
	t_left_fork = get_timestamp();
	write_message(philo, philo->id, "is eating");
	pthread_mutex_lock(&(philo->mutex_t_last_meal));
	philo->t_last_meal = t_left_fork;
	pthread_mutex_unlock(&(philo->mutex_t_last_meal));
	while (get_timestamp() - philo->t_last_meal < rule->time_to_eat)
		usleep(1000);
}

static void	philo_sleep(t_philosopher	*philo)
{
	t_rules	*rule;

	rule = philo->ptr_rules;
	pthread_mutex_unlock(&(rule->forks[philo->right_fork_id]));
	pthread_mutex_unlock(&(rule->forks[philo->left_fork_id]));
	pthread_mutex_lock(&(philo->mutex_x_ate));
	philo->x_ate++;
	pthread_mutex_unlock(&(philo->mutex_x_ate));
	write_message(philo, philo->id, "is sleeping");
	while (1)
	{
		pthread_mutex_lock(&(philo->mutex_t_last_meal));
		if (get_timestamp() - philo->t_last_meal >= \
			rule->time_to_eat + rule->time_to_sleep)
		{
			pthread_mutex_unlock(&(philo->mutex_t_last_meal));
			break ;
		}
		pthread_mutex_unlock(&(philo->mutex_t_last_meal));
		usleep(1000);
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
		write_message(philo, philo->id, "is thinking");
	}
	return (NULL);
}
