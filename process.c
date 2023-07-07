/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:39:56 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/07 11:41:40 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_process(void *ph_struct)
{
	t_philo	*phil;

	phil = (t_philo *)ph_struct;
	phil->info->death_start = 1;
	while (phil->eat_cnt != phil->info->tot_eat && phil->flag_dead != 1)
	{
		pthread_mutex_lock(&(phil->right));
		pthread_mutex_lock(&(phil->left));
		phil->last_action = present();
		print_text(phil->last_action, phil->ph, "has taken a fork");
		while (phil->flag_dead != 1)
			if (phil->info->eat_time + phil->last_action <= present())
				{
					phil->death_time = present() + phil->info->die_time;
					

				}

	}

 //mutex locklar yerleştirilip eat sleep e yönlendirelecek.
 //actionların yazdırılması için bir tane fonksiyon oluştur uygun argümanla ile.
}

void	print_text(long long time, int num, char *str)
{
	printf("%lli philosopher %d %s", time, num, str);
}

void	death_check(void *ph_struct)
{

}
