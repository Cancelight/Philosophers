/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:26:55 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/03 16:17:33 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	error_check(argc, argv);
	parse(argc, argv, data);
}

void	parse(int argc, char **argv, t_data *data)
{
	data->ph_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc != 5)
		data->eat_count = ft_atoi(argv[5]);
	data->philos = malloc(data->ph_count * sizeof(t_philo));
	data->forks = malloc(data->ph_count * sizeof(pthread_mutex_t));
	mt_init(data);
	philo_parse(data);
}

static void	mt_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->ph_count)
		pthread_mutex_init(&(data->forks[i]), NULL);
}

static void	philo_parse(t_data *data)
{
	int	f;
	int	l;

	f = -1;
	l = data->ph_count - 1;
	while(++f <= l)
	{
		if (f == 0)
			data->philos[f].left = data->forks[l];
		else
			data->philos[f].left = data->forks[f - 1];
		data->philos[f].right = data->forks[f];
	}
}
