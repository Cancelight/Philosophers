/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:39:56 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/07 20:01:18 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_process(void *ph_struct)
{
	t_philo	*phil;

	phil = (t_philo *)ph_struct;
	while (phil->eat_cnt != phil->info->tot_eat && !ph_control(phil->info))
	{
		pthread_mutex_lock(phil->right);
		pthread_mutex_lock(phil->left);
		print_text(phil->info, present(), phil->ph, "has taken a fork\n");
		phil->last_action = present() + phil->info->eat_time;
		if (!eating_process(phil))
			break;
		pthread_mutex_unlock(phil->right);
		pthread_mutex_unlock(phil->left);
		if (!sleeping_process(phil))
			break;
	}
	return (0);
}

int	eating_process(t_philo *phil)
{
	if (!ph_control(phil->info))
		print_text(phil->info, present(), phil->ph, "is eating\n");
	while (!ph_control(phil->info))
	{
		if (phil->last_action <= present())
		{
			phil->death_time = present() + phil->info->die_time;
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
	if (!ph_control(phil->info))
		print_text(phil->info, present(), phil->ph, "is sleeping\n");
	while(!ph_control(phil->info))
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
	pthread_mutex_lock(&(info->text));
	printf("%lld philosopher %d %s", (time - info->beginning), num, str);
	pthread_mutex_unlock(&(info->text));
}
