/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:21:49 by khallal           #+#    #+#             */
/*   Updated: 2023/04/13 05:20:11 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_info(t_info *x, pthread_mutex_t *r, int ac, char **av)
{
	int	j;
	int	m;

	j = 0;
	m = atoi(av[1]);
	while (j < m)
	{
		gettimeofday(&(x[j].start_eating), NULL);
		x[j].data = malloc(sizeof(t_philo));
		x[j].eat = r;
		init(x[j].data, av, ac);
		pthread_mutex_init(&x[j].mute, NULL);
		if (j + 1 != m)
			x[j].mute_l = &(x[j + 1].mute);
		else
			x[j].mute_l = &(x[0].mute);
		x[j].id = j + 1;
		j++;
	}
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

int	check_ded(t_info *x, int m)
{
	int	j;

	j = 0;
	while (j < m)
	{
		pthread_mutex_lock(x[j].eat);
		if (timeday () - ((x->start_eating.tv_sec * 1000)
				+ (x->start_eating.tv_usec / 1000)) > x->data->time_die)
		{
			printf("%ld\t%d\t die\n", timeday() - x[j].data->y, x[j].id);
			return (1);
		}
		pthread_mutex_unlock(x[j].eat);
		j++;
	}
	return (0);
}

void	creat_thread(t_info *x, int m)
{
	int	j;

	j = 0;
	while (j < m)
	{
		pthread_create(&x[j].t, NULL, routine, &x[j]);
		j++;
	}
}

int	main(int ac, char **av)
{
	t_info			*x;
	pthread_mutex_t	*r;
	int				j;
	int				m;

	j = 0;
	r = malloc(sizeof(pthread_mutex_t));
	if (ac < 5 || ac > 6)
		return (1);
	if (check_arg(av))
		return (1);
	m = ft_atoi(av[1]);
	x = malloc(sizeof(t_info) * m);
	pthread_mutex_init(r, NULL);
	init_info(x, r, ac, av);
	if (!m || check_arg_val(ac, x[0].data))
		return (1);
	creat_thread(x, m);
	while (1)
	{
		if (check_ded(x, m))
			return (0);
		if (ac == 6 && option(x, m))
			return (0);
	}
}
