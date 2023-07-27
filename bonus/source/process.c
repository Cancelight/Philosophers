/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:39:56 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/26 20:39:09 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*life_process(void *ph_struct)
{
	t_philo	*phil;

	phil = (t_philo *)ph_struct;
	while (phil->eat_cnt != phil->info->tot_eat && !phil->flag_dead)
	{
		sem_wait(phil->info->forks);
		sem_wait(phil->info->forks);
		ph_control(phil);
		wrt_death(phil);
		print_text(phil, present(), phil->ph, "has taken a fork\n");
		phil->last_action = present() + phil->info->eat_time;
		eating_process(phil);
		sem_post(phil->info->forks);
		sem_post(phil->info->forks);
		wrt_death(phil);
		if (ph_control(phil) || phil->flag_dead)
			exit (-1);
		wrt_death(phil);
		if (phil->flag_dead || !sleeping_process(phil))
			exit(-1);
	}
	return (0);
}

int	eating_process(t_philo *phil)
{
	print_text(phil, present(), phil->ph, "is eating\n");
	while (!ph_control(phil) && !phil->flag_dead)
	{
		if (phil->last_action <= present() && !phil->flag_dead)
		{
			phil->death_time = present() + phil->die_time;
			phil->last_action = present() + phil->info->sleep_time;
			phil->eat_cnt++;
			return (1);
		}
		wrt_death(phil);
		usleep(50);
	}
	return (0);
}

int	sleeping_process(t_philo *phil)
{
	if (!phil->flag_dead)
		print_text(phil, present(), phil->ph, "is sleeping\n");
	while (!ph_control(phil) && !phil->flag_dead)
	{
		if (phil->last_action <= present())
		{
			print_text(phil, present(), phil->ph, "is thinking\n");
			return (1);
		}
		wrt_death(phil);
		usleep(50);
	}
	return (0);
}

void	print_text(t_philo *phil, long long time, int num, char *str)
{
	sem_wait(phil->info->text);
	if (!phil->flag_dead)
		printf("%lld ms philosopher %d %s", (time - phil->info->beginning), \
				num, str);
	sem_post(phil->info->text);
}
