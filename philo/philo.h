/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:39:25 by khallal           #+#    #+#             */
/*   Updated: 2023/04/13 04:35:27 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

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
	pthread_mutex_t	mute;
	pthread_mutex_t	*mute_l;
	pthread_mutex_t	*eat;
	pthread_t		t;
	t_philo			*data;
}		t_info;

long	timeday(void);
void	ft_usleep(int k);
void	eating(t_info *x);
void	*routine(void *data);
void	init(t_philo *x, char **av, int ac);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
int		check_arg(char **av);
int		option(t_info *x, int m);

#endif