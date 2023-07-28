/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:39:56 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/28 14:22:18 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_process(void *ph_struct)
{
	t_philo	*phil;

	phil = (t_philo *)ph_struct;
	while (phil->eat_cnt != phil->info->tot_eat && !phil->flag_dead)
	{
		pthread_mutex_lock(phil->left);
		pthread_mutex_lock(phil->right);
		ph_control(phil);
		wrt_death(phil);
		print_text(phil, present(), phil->ph, "has taken forks\n");
		phil->last_action = present() + phil->info->eat_time;
		wrt_death(phil);
		eating_process(phil);
		pthread_mutex_unlock(phil->right);
		pthread_mutex_unlock(phil->left);
		wrt_death(phil);
		if (ph_control(phil) || phil->flag_dead)
			break ;
		wrt_death(phil);
		if (phil->flag_dead || !sleeping_process(phil))
			break ;
		wrt_death(phil);
	}
	return (0);
}

int	eating_process(t_philo *phil)
{
	if (!phil->flag_dead)
		print_text(phil, present(), phil->ph, "is eating\n");
	while (!ph_control(phil) && !phil->flag_dead)
	{
		wrt_death(phil);
		if (phil->last_action <= present() && !phil->flag_dead)
		{
			phil->death_time = present() + phil->die_time;
			phil->last_action = present() + phil->info->sleep_time;
			phil->eat_cnt++;
			return (1);
		}
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
		wrt_death(phil);
		if (phil->last_action <= present() && !phil->flag_dead)
		{
			print_text(phil, present(), phil->ph, "is thinking\n");
			return (1);
		}
		usleep(50);
	}
	return (0);
}

void	print_text(t_philo *phil, long long time, int num, char *str)
{
	pthread_mutex_lock(&phil->info->text);
	wrt_death(phil);
	if (!phil->flag_dead)
		printf("%lld ms philosopher %d %s", (time - phil->info->beginning), \
				num, str);
	pthread_mutex_unlock(&phil->info->text);
}
