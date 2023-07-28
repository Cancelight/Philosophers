/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:26:55 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/28 14:27:23 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	error_check(argc, argv);
	data = malloc(sizeof(t_data));
	parse(argc, argv, data);
	nav(data);
}

void	nav(t_data *data)
{
	if (data->ph_count == 1)
		one_philo(data);
	else if (data->ph_count > 1)
		thread_begin(data);
}

void	one_philo(t_data *data)
{
	printf("%lld ms Philosopher %d has taken a fork\n", \
		present() - data->beginning, data->philos[0].ph);
	while(!data->philos[0].flag_dead)
	{
		ph_control(&data->philos[0]);
		usleep(50);
	}
}
