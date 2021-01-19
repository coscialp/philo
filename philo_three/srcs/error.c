/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 09:51:34 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/18 09:37:45 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ft_error(char *msg)
{
	ft_write(2, "\033[0;31;5;110mError:\033[0m\t", 25);
	ft_write(2, msg, ft_strlen(msg));
	return (1);
}
