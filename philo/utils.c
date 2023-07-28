/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:54:01 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/21 11:24:09 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_begin(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->ph_count)
	{
		if (pthread_create(&data->philos[i].action, NULL, \
					life_process, &data->philos[i]))
			exit_prog("threads are not created succesfully.");
	}
	i = -1;
	while (++i < data->ph_count)
		pthread_join(data->philos[i].action, NULL);
}

long long	present(void)
{
	struct timeval	tval;

	gettimeofday(&tval, NULL);
	return ((((long long)tval.tv_sec) * 1000) + (tval.tv_usec / 1000));
}

int	ft_isdigit(char *str)
{
	int	i;

	if (str == NULL || str[0] == 0)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (!(str[i] <= 57 && str[i] >= 48))
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *s)
{
	int		i;
	long	back;
	int		np;

	back = 0;
	np = 1;
	i = 0;
	while ((s[i] <= 13 && s[i] >= 9) || s[i] == 32)
		i++;
	if (s[i] == 43 || s[i] == 45)
	{
		if (s[i] == 45)
			np *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		back = back * 10 + (s[i] - 48) * np;
		if (back > 2147483647)
			return (-1);
		if (back < -2147483648)
			return (0);
		i++;
	}
	return ((int)back);
}

void	wrt_death(t_philo *phil)
{
	pthread_mutex_lock(&phil->info->flag_change);
	phil->flag_dead = phil->info->gen_death;
	pthread_mutex_unlock(&phil->info->flag_change);
}
