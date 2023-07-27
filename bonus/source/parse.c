/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:26:28 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/27 17:46:09 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	parse(int argc, char **argv, t_data *data)
{
	data->ph_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc != 5)
		data->tot_eat = ft_atoi(argv[5]);
	else
		data->tot_eat = -1;
	data->beginning = present();
	data->philos = malloc(data->ph_count * sizeof(t_philo));
	philo_parse(data);
	sem_linkage();
	sem_creation(data);
}

void	philo_parse(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->ph_count)
	{
		data->philos[i].eat_cnt = 0;
		data->philos[i].ph = i + 1;
		data->philos[i].info = data;
		data->philos[i].die_time = data->die_time;
		data->philos[i].death_time = data->philos[i].die_time + data->beginning;
	}
}

void	sem_linkage(void)
{
	sem_unlink("/fork");
	sem_unlink("/text");
}

void	sem_creation(t_data *data)
{
	data->forks = sem_open("/fork", O_CREAT, S_IRWXU, data->ph_count);
	data->text = sem_open("/text", O_CREAT, S_IRWXU, 1);
}
