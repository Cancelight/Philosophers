/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:39:56 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/20 17:49:59 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_process(void *ph_struct)
{
	t_philo	*phil;

	phil = (t_philo *)ph_struct;
	while (phil->eat_cnt != phil->info->tot_eat && !phil->info->gen_death)
	{
		pthread_mutex_lock(phil->left);
		pthread_mutex_lock(phil->right);
		ph_control(phil);
		print_text(phil->info, present(), phil->ph, "has taken a fork\n");
		phil->last_action = present() + phil->info->eat_time;
		eating_process(phil);
		pthread_mutex_unlock(phil->right);
		pthread_mutex_unlock(phil->left);
		if (ph_control(phil))
			break;
		if (!sleeping_process(phil))
			break;
	}
	return (0);
}

int	eating_process(t_philo *phil)
{
	print_text(phil->info, present(), phil->ph, "is eating\n");
	while (!ph_control(phil) && !phil->info->gen_death)
	{
		if (phil->last_action <= present() && !phil->info->gen_death)
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
	if (!phil->info->gen_death)
		print_text(phil->info, present(), phil->ph, "is sleeping\n");
	while(!ph_control(phil) && !phil->info->gen_death)
	{
		if (phil->last_action <= present())
		{
			print_text(phil->info, present(), phil->ph, "is thinking\n");
			return (1);
		}
		usleep(50);
	}
	return (0);
}

void	print_text(t_data *info, long long time, int num, char *str)
{
	pthread_mutex_lock(&info->text);
	if (!info->gen_death)
		printf("%lld ms philosopher %d %s", (time - info->beginning), num, str);
	pthread_mutex_unlock(&info->text);
}
