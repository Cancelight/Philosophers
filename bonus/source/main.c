/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:26:55 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/26 16:12:47 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		write(1, "bir philo için fonksiyon", 20);
	else if (data->ph_count > 1)
		children_post(data);
}
