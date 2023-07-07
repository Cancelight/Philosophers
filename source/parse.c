/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:26:28 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/07 19:13:05 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	data->forks = malloc(data->ph_count * sizeof(pthread_mutex_t));
	philo_parse(data);
	mt_init(data);
	philo_mt_parse(data);
}

void	philo_parse(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->ph_count)
	{
		data->philos[i].eat_cnt = 0;
		data->philos[i].flag_dead = 0;
		data->philos[i].ph = i + 1;
		data->philos[i].info = data;
		data->philos[i].death_time = data->die_time + data->beginning;
	}
}

void	mt_init(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&data->control, NULL);
	pthread_mutex_init(&(data->text), NULL);
	while (++i < data->ph_count)
		pthread_mutex_init(&(data->forks[i]), NULL);
}

void	philo_mt_parse(t_data *data)
{
	int	f;
	int	l;

	f = -1;
	l = data->ph_count - 1;
	while(++f <= l)
	{
		if (f == 0)
			data->philos[f].left = &(data->forks[l]);
		else
			data->philos[f].left = &(data->forks[f - 1]);
		data->philos[f].right = (&data->forks[f]);
	}
}
