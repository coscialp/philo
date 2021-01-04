/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:51:12 by coscialp          #+#    #+#             */
/*   Updated: 2020/12/18 11:52:30 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*ft_calloc(size_t size, size_t count)
{
	void	*ptr;

	ptr = malloc(size * count);
	memset(ptr, 0, size * count);
	return (ptr);
}
