/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:39:56 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/06 18:00:33 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_process(void *ph_struct)
{
	t_philo	*phil;

	phil = (t_philo *)ph_struct ;
	while (phil->eat_cnt != phil->info->tot_eat && phil->flag_dead != 1)
	{
		pthread_mutex_lock(&(phil->right));
		pthread_mutex_lock(&(phil->left));
		//print fonksiyonu
	}

 //mutex locklar yerleştirilip eat sleep e yönlendirelecek.
 //actionların yazdırılması için bir tane fonksiyon oluştur uygun argümanla ile.
}

void	death_check(void *ph_struct)
{

}
