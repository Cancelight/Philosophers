/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:28:51 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/20 20:00:34 by bkiziler         ###   ########.fr       */
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
	long long		death_time; //devamlı güncellenen ölüm saati
	int				die_time;
	int				eat_cnt;
	int				flag_dead;
	long long		last_action; //yazdırmak için zaman
	struct s_data	*info;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}					t_philo;

typedef struct s_data {
	t_philo			*philos;
	int				ph_count;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				tot_eat;
	long long		beginning;
	int				gen_death;
	pthread_mutex_t flag_change;
	pthread_mutex_t	text;
	pthread_mutex_t	*forks;
}					t_data;


void		error_check(int argc, char **argv);
int			ft_isdigit(char *str);
void		exit_prog(char *str);
int			ft_atoi(const char *s);
void		parse(int argc, char **argv, t_data *data);
void		thread_begin(t_data *data);
void		*life_process(void *each_ph);
void		nav(t_data *data);
void		philo_parse(t_data *data);
void		mt_init(t_data *data);
void		philo_mt_parse(t_data *data);
void		check_digit(int argc, char **argv);
void		check_count(int argc);
long long	present(void);
int			ph_control(t_philo *phil);
void		print_text(t_philo *phil, long long time, int num, char *str);
int			sleeping_process(t_philo *phil);
int			eating_process(t_philo *phil);
void		wrt_death(t_philo *phil);



#endif
