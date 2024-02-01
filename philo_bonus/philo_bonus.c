/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:51:44 by khallal           #+#    #+#             */
/*   Updated: 2023/04/13 05:29:18 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	initiiii(t_philo_bonus *bon, char **av, int m)
{
	sem_unlink("sema_main");
	sem_unlink("r");
	bon->r = malloc(sizeof(sem_t));
	bon->fo = malloc(sizeof(int) * m);
	bon->sema_main = malloc(sizeof(sem_t));
	bon->r = sem_open("r", O_CREAT, 0644, 1);
	bon->eat = sem_open("eat", O_CREAT, 0644, 1);
	bon->sema_main = sem_open("sema_main", O_CREAT, 0644, m);
	bon->m = ft_atoi(av[1]);
	bon->j = 0;
}

void	init_info(t_philo_bonus *bon, t_info *x, char **av, int ac)
{
	while (bon->j < bon->m)
	{
		gettimeofday(&(x[bon->j].start_eating), NULL);
		x[bon->j].data = malloc(sizeof(t_philo));
		init(x[bon->j].data, av, ac);
		x[bon->j].lock = bon->r;
		x[bon->j].eat = bon->eat;
		x[bon->j].sema = bon->sema_main;
		x[bon->j].id = bon->j + 1;
		bon->j++;
	}
}

void	creat_process(t_philo_bonus *bon, t_info *x, int ac)
{
	bon->j = 0;
	while (bon->j < bon->m)
	{
		bon->f = fork();
		bon->fo[bon->j] = bon->f;
		if (bon->f == 0)
		{
			routine(&x[bon->j], ac);
		}
		else
			bon->j++;
	}
}

int	check_die(t_philo_bonus *bon)
{
	if (bon->status == 12)
	{
		bon->j = 0;
		while (bon->j < bon->m)
		{
			kill(bon->fo[bon->j], SIGKILL);
			bon->j++;
		}
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_info			*x;
	t_philo_bonus	*bon;
	int				m;

	if ((ac != 5 && ac != 6) || check_arg(av))
		return (1);
	m = ft_atoi(av[1]);
	x = malloc(sizeof(t_info) * m);
	bon = malloc(sizeof(t_philo_bonus));
	initiiii(bon, av, m);
	init_info(bon, x, av, ac);
	if (m == 0 || check_arg_val(ac, x[0].data))
		return (1);
	creat_process(bon, x, ac);
	bon->j = 0;
	while (bon->j++ < m)
	{
		waitpid(-1, &bon->status, 0);
		bon->status = WEXITSTATUS(bon->status);
		if (check_die(bon) == 1)
			return (1);
	}
	return (0);
}
