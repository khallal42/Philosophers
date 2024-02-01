/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:29:04 by khallal           #+#    #+#             */
/*   Updated: 2023/04/11 17:43:58 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	option(t_info *x, int m)
{
	int	j;

	j = 0;
	pthread_mutex_lock(x[j].eat);
	while (j < m)
	{
		if (x[j].data->num_eat < x[j].data->option)
			break ;
		j++;
		if (x[j].data->num_eat >= x[j].data->option && j + 1 == m)
			return (1);
	}
	pthread_mutex_unlock(x[j].eat);
	return (0);
}
