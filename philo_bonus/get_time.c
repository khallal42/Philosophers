/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:52:17 by khallal           #+#    #+#             */
/*   Updated: 2023/04/11 17:36:27 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(int k)
{
	long	h;

	h = timeday();
	while (timeday() - h < k)
		usleep (210);
}

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

int	check_arg_val(int ac, t_philo *x)
{
	if (x->num_philo == 0 || x->time_die == 0
		|| x->time_eat == 0 || x->time_sleep == 0)
		return (1);
	if (ac == 6 && x->option == 0)
		return (1);
	return (0);
}
