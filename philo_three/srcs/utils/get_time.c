/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 09:29:37 by coscialp          #+#    #+#             */
/*   Updated: 2020/12/18 13:49:04 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

long int	get_time(void)
{
	struct timeval tv[1];

	gettimeofday(tv, NULL);
	return (tv->tv_sec * 1000 + tv->tv_usec / 1000);
}
