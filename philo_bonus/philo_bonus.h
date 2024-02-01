/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:53:28 by khallal           #+#    #+#             */
/*   Updated: 2023/04/11 17:40:17 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/time.h>

typedef struct s_philo_bonus
{
	int		m;
	sem_t	*r;
	sem_t	*sema_main;
	sem_t	*eat;
	int		j;
	int		f;
	int		status;
	int		*fo;
}		t_philo_bonus;

typedef struct s_philo
{
	int		num_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		option;
	int		num_eat;
	long	y;
}		t_philo;

typedef struct s_info
{
	struct timeval	start_eating;
	int				id;
	sem_t			*sema;
	sem_t			*lock;
	sem_t			*eat;
	pthread_t		t;
	t_philo			*data;
}		t_info;

int		ft_atoi(char *str);
long	timeday(void);
void	ft_usleep(int k);
void	routine(t_info *x, int ac);
void	*routine_die(void *in);
void	init(t_philo *x, char **av, int ac);
int		check_arg(char **av);
int		ft_isdigit(int c);
int		check_arg_val(int ac, t_philo *x);

#endif