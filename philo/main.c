/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:26:55 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/29 14:54:30 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// hem yeme hem sleep 0 verildiğinde sonsuza gidiyor

int	main(int argc, char **argv)
{
	t_data	*data;

	error_check(argc, argv);
	data = malloc(sizeof(t_data));
	parse(argc, argv, data);
	nav(data);
}
