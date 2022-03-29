/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:52:19 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/29 15:03:45 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	write_message(t_philosopher *philo, int id, char *msg)
{
	pthread_mutex_lock(&(philo->ptr_rules->mutex_writing));
	printf("%lld %d %s\n", get_timestamp(), id, msg);
	pthread_mutex_unlock(&(philo->ptr_rules->mutex_writing));
}
