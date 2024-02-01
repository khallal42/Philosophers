/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:20:51 by khallal           #+#    #+#             */
/*   Updated: 2023/04/07 17:21:31 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timeday(void)
{
	long			i;
	struct timeval	tv;

	i = 0;
	gettimeofday(&tv, NULL);
	tv.tv_usec /= 1000;
	tv.tv_sec *= 1000;
	i = tv.tv_sec + tv.tv_usec;
	return (i);
}
