/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:39:51 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/27 17:39:56 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	error_check(int argc, char **argv)
{
	check_count(argc);
	check_digit(argc, argv);
}

void	check_count(int argc)
{
	if (argc == 5 || argc == 6)
		return ;
	else
		exit_prog("Invalid argument count.");
}

void	check_digit(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isdigit(argv[i++]))
			exit_prog("Non-natural numeric arguments.");
	}
	return ;
}

int	ph_control(t_philo *phil)
{
	int static written= 0;
	sem_wait(phil->info->text);
	if (phil->death_time <= present() && !phil->info->gen_death)
	{
		phil->flag_dead = 1;
		usleep(230);
		if (!written)
		{
			printf("%lld ms Philosopher %d is dead\n", \
			present() - phil->info->beginning, phil->ph);
			written = 1;
		}
		exit (-1);
/*		sem_wait(phil->info->flag_change);
		phil->info->gen_death = phil->flag_dead;
		sem_post(phil->info->flag_change);*/
		sem_post(phil->info->text);
	}
	sem_post(phil->info->text);
	return (0);
}

void	exit_prog(char *str)
{
	printf("%s", str);
	exit(0);
}
