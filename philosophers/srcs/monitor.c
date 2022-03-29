/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:58:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/29 09:47:48 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	all_ate_philo(t_philosopher	*philo, bool *is_ate)
{
	pthread_mutex_lock(&(philo->mutex_x_ate));
	if (philo->x_ate > philo->ptr_rules->nb_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&(philo->ptr_rules->mutex_x_all_ate_philos));
		philo->ptr_rules->x_all_ate_philos++;
		if (philo->ptr_rules->x_all_ate_philos == philo->ptr_rules->nb_philo)
			pthread_mutex_unlock(&(philo->ptr_rules->mutex_finish_pgm));
		pthread_mutex_unlock(&(philo->ptr_rules->mutex_x_all_ate_philos));
		*is_ate = true;
	}
	pthread_mutex_unlock(&(philo->mutex_x_ate));
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
			pthread_mutex_lock(&(philo->ptr_rules->mutex_writing));
			printf("%lld %d %s\n", timestamp, philo->id, "died");
			pthread_mutex_unlock(&(philo->ptr_rules->mutex_finish_pgm));
			return (0);
		}
		pthread_mutex_unlock(&(philo->mutex_t_last_meal));
		if (! is_ate)
			all_ate_philo(philo, &is_ate);
		usleep(1000 * 3);
	}
	return (NULL);
}
