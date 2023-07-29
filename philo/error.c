/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:39:51 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/29 14:01:35 by bkiziler         ###   ########.fr       */
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
			exit_prog("Non-natural numeric arguments.");
	}
	return ;
}

void	exit_prog(char *str)
{
	printf("%s", str);
	exit(0);
}
