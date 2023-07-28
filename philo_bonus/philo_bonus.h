/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:28:51 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/28 15:36:26 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_philo {
	int				ph;
	pthread_t		action;
	long long		death_time;
	int				die_time;
	int				eat_cnt;
	long long		last_action;
	struct s_data	*info;
}					t_philo;

typedef struct s_data {
	t_philo			*philos;
	int				ph_count;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				tot_eat;
	long long		beginning;
	sem_t			*text;
	sem_t			*forks;
}					t_data;

void		error_check(int argc, char **argv);
int			ft_isdigit(char *str);
void		exit_prog(char *str);
int			ft_atoi(const char *s);
void		parse(int argc, char **argv, t_data *data);
void		children_post(t_data *data);
void		*life_process(void *each_ph);
void		nav(t_data *data);
void		philo_parse(t_data *data);
void		sem_linkage(void);
void		sem_creation(t_data *data);
void		check_digit(int argc, char **argv);
void		check_count(int argc);
long long	present(void);
int			ph_control(t_philo *phil);
void		print_text(t_philo *phil, long long time, int num, char *str);
int			sleeping_process(t_philo *phil);
int			eating_process(t_philo *phil);
void		ending_children(t_data *data, int *pid);
void		one_philo(t_data *data);
void		unlinkage(t_data *data);

#endif
