/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:48:37 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/29 17:24:46 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	nav(t_data *data)
{
	if (data->ph_count == 1)
		one_philo(data);
	else if (data->ph_count > 1)
		children_post(data);
	unlinkage(data);
}

void	one_philo(t_data *data)
{
	sem_wait(data->forks);
	printf("%lld ms Philosopher %d has taken a fork\n", \
		present() - data->beginning, data->philos[0].ph);
	while (1)
	{
		if (ph_control(&data->philos[0]))
			break ;
		usleep(50);
	}
	sem_post(data->forks);
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
		if (pid[i] < 0)
		{
			free(pid);
			exit (-1);
		}
		if (pid[i] == 0)
			life_process(&data->philos[i]);
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
	if (end != 0)
	{
		while (++i < data->ph_count)
			kill(pid[i], 15);
		sem_post(data->text);
	}
	else
		while (waitpid(-1, &end, 0) != -1)
			;
	free (pid);
}

void	unlinkage(t_data *data)
{
	sem_unlink("/text");
	sem_unlink("/fork");
	sem_close(data->text);
	sem_close(data->forks);
}
