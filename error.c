/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:39:51 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/07 12:12:29 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_check(int argc, char **argv)
{
	check_count(argc);
	check_digit(argc, argv);
}

void	check_count(int argc)
{
	if (argc == 5 || argc == 6)
		return ;
	else
		exit_prog("Invalid argument count.");
}

void	check_digit(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isdigit(argv[i++]))
			exit_prog("Non-numeric arguments.");
	}
	return ;
}

int	ph_control(t_data *data)
{
	int	i;

	i = -1;
	while(++i < data->ph_count)
	{
		if (data->philos[i].flag_dead)
			return (0);
	}
	return (1);
}

void	exit_prog(char *str)
{
	printf("%s",str);
	exit(0);
}
