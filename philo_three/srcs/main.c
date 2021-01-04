/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:08:50 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/04 11:22:11 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_state		*state(void)
{
	static t_state s = {0};

	return (&s);
}

void		*th_brain(void *philo_ptr)
{
	t_philosoph	*philo;

	philo = (t_philosoph *)philo_ptr;
	while (philo->is_dead)
	{
		if (state()->end)
			break ;
		sem_wait(philo->sem_check);
		if (ft_is_dead(philo))
		{
			philo->is_dead = 0;
			display(philo, "died");
			sem_post(philo->sem_check);
			kill(philo->pid, SIGINT);
			return (NULL);
		}
		sem_post(philo->sem_check);
		usleep(3000);
	}
	kill(philo->pid, SIGINT);
	return (NULL);
}

void		th_routine(void *philo_ptr)
{
	t_philosoph	*philo;

	philo = (t_philosoph *)philo_ptr;
	philo->last_meal = state()->begin_time;
	pthread_create(&philo->brain, NULL, th_brain, philo);
	while (philo->is_dead && !state()->end)
	{
		if (ft_eat(philo))
			break ;
		ft_sleep(philo);
		ft_think(philo);
	}
	pthread_join(philo->brain, NULL);
	exit(0);
}

void		*th_eating(void *ptr)
{
	int		i;
	int		sval;

	(void)ptr;
	i = 0;
	// dprintf(1, "%d\n", state()->rules.number_of_philo);
	while (1)
	{
		// dprintf(1, "%d %d\n", state()->philosoph->id, sem_getvalue(state()->philosoph->sem_eat, &sval));
		sem_wait(state()->philosoph->sem_eat);
		i++;
		// puts("mabite");
		if (i == state()->rules.number_of_philo - 1)
			break ;
		state()->philosoph = state()->philosoph->right;
	}
	i = -1;
	while (++i < state()->rules.number_of_philo)
	{
		kill(state()->philosoph->pid, SIGINT);
		state()->philosoph = state()->philosoph->right;
	}
	return (NULL);
}

int			main(int ac, char **av)
{
	static int		i = -1;
	static int		status = 0;
	pthread_t		end_game;

	if (init_state(ac, av))
		return (1);
	gettimeofday(&state()->begin_time, NULL);
	state()->time = get_time();
	if (state()->rules.number_of_must_eat != -1)
		pthread_create(&end_game, NULL, th_eating, NULL);
	while (++i < state()->rules.number_of_philo)
	{
		state()->philosoph->pid = fork();
		if (!state()->philosoph->pid)
		{
			th_routine(state()->philosoph);
			exit(0);
		}
		usleep(1000);
		state()->philosoph = state()->philosoph->right;
	}
	if (waitpid(-1, &status, 0) < 0)
		exit(0);
	i = -1;
	while (++i < state()->rules.number_of_philo)
	{
		kill(state()->philosoph->pid, SIGINT);
		state()->philosoph = state()->philosoph->right;
	}
	if (state()->rules.number_of_must_eat != -1)
		pthread_join(end_game, NULL);
	destroy_sem();
	return (0);
}
