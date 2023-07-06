/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:39:56 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/06 17:27:39 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_process(void *ph_struct)
{
	while (((t_philo *)ph_struct)->eat_cnt != ((t_philo *)ph_struct)->info->tot_eat
	&& ((t_philo *)ph_struct)->flag_dead != 1)
	{
		pthread_mutex_lock(&(((t_philo *)ph_struct)->right));
		pthread_mutex_lock(&(((t_philo *)ph_struct)->left));
		//print fonksiyonu
	}

 //mutex locklar yerleştirilip eat sleep e yönlendirelecek.
 //actionların yazdırılması için bir tane fonksiyon oluştur uygun argümanla ile.
}

void	death_check(void *ph_struct)
{

}
