/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:58:35 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/21 09:51:13 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_sleep(t_philosoph *philo)
{
	display(philo, "is sleeping");
	usleep(state()->rules.time_to_sleep * 1000);
}

int		ft_eat(t_philosoph *philo)
{
	if (state()->rules.number_of_philo == 1)
	{
		sem_wait(state()->forks);
		display(philo, "has taken a fork");
		usleep(state()->rules.time_to_die * 1000);
		return (1);
	}
	sem_wait(state()->forks);
	sem_wait(state()->forks);
	display(philo, "has taken a fork");
	display(philo, "has taken a fork");
	sem_wait(philo->sem_check);
	philo->eating++;
	display(philo, "is eating");
	if (philo->eating == state()->rules.number_of_must_eat)
		state()->eating++;
	if (state()->eating == state()->rules.number_of_philo)
		state()->end = 1;
	gettimeofday(&philo->last_meal, NULL);
	sem_post(philo->sem_check);
	usleep(state()->rules.time_to_eat * 1000);
	sem_post(state()->forks);
	sem_post(state()->forks);
	return (0);
}

void	ft_think(t_philosoph *philo)
{
	display(philo, "is thinking");
}
