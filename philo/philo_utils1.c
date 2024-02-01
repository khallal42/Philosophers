/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:22:53 by khallal           #+#    #+#             */
/*   Updated: 2023/04/13 04:41:35 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int k)
{
	long	h;

	h = timeday();
	while (timeday() - h < k)
		usleep (210);
}

void	eating(t_info *x)
{
	pthread_mutex_lock(&x->mute);
	printf("%ld %d taken a fork\n", timeday() - x->data->y, x->id);
	pthread_mutex_lock(x->mute_l);
	printf("%ld %d taken a fork\n", timeday() - x->data->y, x->id);
	printf("%ld %d start eaten\n", timeday() - x->data->y, x->id);
	pthread_mutex_lock(x->eat);
	gettimeofday(&(x->start_eating), NULL);
	pthread_mutex_unlock(x->eat);
	pthread_mutex_lock(x->eat);
	x->data->num_eat++;
	pthread_mutex_unlock(x->eat);
	ft_usleep(x->data->time_eat);
	pthread_mutex_unlock(&x->mute);
	pthread_mutex_unlock(x->mute_l);
}

void	*routine(void *data)
{
	t_info	*x;

	x = (t_info *)data;
	if (x->id % 2 == 0)
		usleep(600);
	while (1)
	{
		eating(x);
		pthread_mutex_lock(x->eat);
		printf("%ld %d has sleeped\n", timeday() - x->data->y, x->id);
		pthread_mutex_unlock(x->eat);
		ft_usleep(x->data->time_sleep);
		pthread_mutex_lock(x->eat);
		printf("%ld %d is tinking\n", timeday() - x->data->y, x->id);
		pthread_mutex_unlock(x->eat);
	}
	return (NULL);
}

void	init(t_philo *x, char **av, int ac)
{
	x->num_philo = ft_atoi(av[1]);
	x->time_die = ft_atoi(av[2]);
	x->time_eat = ft_atoi(av[3]);
	x->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		x->option = ft_atoi(av[5]);
	x->num_eat = 0;
	x->y = timeday();
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
