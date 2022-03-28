/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:52:19 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/29 08:04:13 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_monitor(t_rules *rule)
{
	pthread_t		thread;
	int				i;

	i = 0;
	while (i < rule->nb_philo)
	{
		if (pthread_create(&thread, NULL, monitor, &rule->philo[i++]) != 0)
			return (1);
		pthread_detach(thread);
	}
	return (0);
}

int	launch_philo(t_rules *rule)
{
	pthread_t		thread;
	int				i;

	i = 0;
	while (i * 2 < rule->nb_philo)
	{
		if (pthread_create(&thread, NULL, philo, &rule->philo[i]) != 0)
			return (1);
		pthread_detach(thread);
		if (i == rule->nb_philo - i - 2)
			break ;
		if (pthread_create(&thread, NULL, philo, \
			&rule->philo[rule->nb_philo - i - 2]) != 0)
			return (1);
		pthread_detach(thread);
		i += 2;
	}
	i = 0;
	while (++i < rule->nb_philo)
	{
		if (pthread_create(&thread, NULL, philo, &rule->philo[i++]) != 0)
			return (1);
		pthread_detach(thread);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_rules			rule;

	init_rule(&rule, argc, argv);
	init_philo(&rule);
	if (launch_monitor(&rule) == 1)
		return (1);
	if (launch_philo(&rule) == 1)
		return (1);
	pthread_mutex_lock(&(rule.mutex_finish_pgm));
	pthread_mutex_unlock(&(rule.mutex_finish_pgm));
	return (0);
}
