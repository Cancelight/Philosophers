/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:26:28 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/21 11:21:26 by bkiziler         ###   ########.fr       */
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
	data->gen_death = 0;
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
		data->philos[i].die_time = data->die_time;
		data->philos[i].death_time = data->philos[i].die_time + data->beginning;
	}
}

void	mt_init(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&data->text, NULL);
	pthread_mutex_init(&data->flag_change, NULL);
	while (++i < data->ph_count)
		pthread_mutex_init(&data->forks[i], NULL);
}

void	philo_mt_parse(t_data *data)
{
	int	f;

	f = -1;
	while (++f < data->ph_count)
	{
		data->philos[f].left = &data->forks[f];
		data->philos[f].right = &data->forks[(f + 1) % (data->ph_count)];
	}
}
