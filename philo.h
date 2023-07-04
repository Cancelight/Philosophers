/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:28:51 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/04 17:01:29 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo {
	int				ph;
	pthread_t		action;
	pthread_t		death_cont;
	int				death_time; // geri sayım için devamlı güncellenen ölüm
	int				eat_count;
	int				flag_dead;
	long long		last_action;
	pthread_mutex_t	right;
	pthread_mutex_t	left;
}					t_philo;

typedef struct s_data {
	t_philo			*philos;
	int				ph_count;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	long long		beg_time;
	int				thrror_action;
	int				thrror_death;
	pthread_mutex_t	*forks;
}					t_data;

void	error_check(int argc, char **argv);
int		ft_isdigit(char *str);
int		ft_strlen(char *s);
void	exit_prog(char *str);
int		ft_atoi(const char *s);
void	parse(int argc, char **argv, t_data *data);
void	thread_begin(t_data *data);

#endif
