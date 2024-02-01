/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:59:16 by khallal           #+#    #+#             */
/*   Updated: 2023/04/12 02:00:07 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	*routine_die(void *in)
{
	t_info	*x;

	x = (t_info *)in;
	gettimeofday(&(x->start_eating), NULL);
	while (timeday () - ((x->start_eating.tv_sec * 1000)
			+ (x->start_eating.tv_usec / 1000)) < x->data->time_die)
		usleep(100);
	sem_wait(x->lock);
	printf("%ld\t%d\t die\n", timeday() - x->data->y, x->id);
	exit(12);
	return (NULL);
}

void	routine(t_info *x, int ac)
{
	pthread_create(&x->t, NULL, routine_die, x);
	while (1)
	{
		sem_wait(x->sema);
		printf("%ld %d taken a fork\n", timeday() - x->data->y, x->id);
		sem_wait(x->sema);
		printf("%ld %d taken a fork\n", timeday() - x->data->y, x->id);
		printf("%ld %d start eaten\n", timeday() - x->data->y, x->id);
		gettimeofday(&(x->start_eating), NULL);
		sem_wait(x->lock);
		x->data->num_eat++;
		sem_post(x->lock);
		ft_usleep(x->data->time_eat);
		sem_post(x->sema);
		sem_post(x->sema);
		if (ac == 6 && x->data->num_eat == x->data->option)
			exit(0);
		sem_wait(x->lock);
		printf("%ld %d has sleeped\n", timeday() - x->data->y, x->id);
		sem_post(x->lock);
		ft_usleep(x->data->time_sleep);
		sem_wait(x->lock);
		printf("%ld %d is tinking\n", timeday() - x->data->y, x->id);
		sem_post(x->lock);
	}
}

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

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
