/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:57:21 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/29 14:32:59 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	nav(t_data *data)
{
	if (data->ph_count == 1)
		one_philo(data);
	else if (data->ph_count > 1)
		thread_begin(data);
}

void	one_philo(t_data *data)
{
	pthread_mutex_lock(&data->forks[0]);
	printf("%lld ms Philosopher %d has taken a fork\n", \
		present() - data->beginning, data->philos[0].ph);
	while (!data->philos[0].flag_dead)
	{
		ph_control(&data->philos[0]);
		usleep(50);
	}
	pthread_mutex_unlock(&data->forks[0]);
}

void	thread_begin(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->ph_count)
	{
		if (pthread_create(&data->philos[i].action, NULL, \
					life_process, &data->philos[i]))
			exit_prog("threads are not created succesfully.");
	}
	i = -1;
	while (++i < data->ph_count)
		pthread_join(data->philos[i].action, NULL);
}
