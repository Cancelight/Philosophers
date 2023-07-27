/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:48:37 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/27 18:14:44 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	nav(t_data *data)
{
	if (data->ph_count == 1)
		one_philo(data);
	else if (data->ph_count > 1)
		children_post(data);
}

void	one_philo(t_data *data)
{
	printf("%lld ms Philosopher %d hsa taken a fork\n", \
		present() - data->beginning, data->philos[0].ph);
	while (1)
	{
		ph_control(&data->philos[0]);
		usleep(50);
	}
}

void	children_post(t_data *data)
{
	int		i;
	int		*pid;

	pid = malloc(sizeof(int) * data->ph_count);
	i = -1;
	while (++i < data->ph_count)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			life_process(&data->philos[i]);
			break;
		}
		usleep(100);
	}
	ending_children(data, pid);
}

void	ending_children(t_data *data, int *pid)
{
	int	i;
	int	end;

	i = -1;
	waitpid(-1, &end, 0);
	printf("end değeri : %d", end);
	while(++i < data->ph_count)
		kill(pid[i], 15);
	if (end != 0)
		sem_post(data->text);
	free (pid);
	sem_unlink("/text");
	sem_unlink("/fork");
	sem_close(data->text);
	sem_close(data->forks);
}
