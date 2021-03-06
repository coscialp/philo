/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:55:23 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/20 12:37:28 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		destroy_mutex(void)
{
	int			i;
	t_philosoph	*tmp;
	t_fork		*tmp_fork;

	i = -1;
	while (++i < state()->rules.number_of_philo)
	{
		pthread_mutex_destroy(&state()->philosoph->l_fork->mutex);
		pthread_mutex_destroy(&state()->philosoph->r_fork->mutex);
		pthread_mutex_destroy(&state()->philosoph->mutex_check);
		pthread_mutex_destroy(&state()->philosoph->mutex_eat);
		tmp = state()->philosoph->right;
		free(state()->philosoph);
		state()->philosoph = tmp;
	}
	i = -1;
	while (++i < state()->rules.number_of_philo)
	{
		tmp_fork = state()->fork->right;
		free(state()->fork);
		state()->fork = tmp_fork;
	}
	pthread_mutex_destroy(&state()->mutex_write);
	pthread_mutex_destroy(&state()->mutex_state);
	pthread_mutex_destroy(&state()->mutex_fork);
}

int			ft_is_dead(t_philosoph *philo)
{
	static struct timeval now;

	gettimeofday(&now, NULL);
	if (get_timestamp(philo->last_meal, now) > state()->rules.time_to_die)
		return (1);
	return (0);
}
