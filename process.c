/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:39:56 by bkiziler          #+#    #+#             */
/*   Updated: 2023/07/07 13:42:34 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_process(void *ph_struct)
{
	t_philo	*phil;

	phil = (t_philo *)ph_struct;
	while (phil->eat_cnt != phil->info->tot_eat && ph_control(phil->info))
	{
		pthread_mutex_lock(&(phil->right));
		pthread_mutex_lock(&(phil->left));
		phil->last_action = present();
		print_text(phil->last_action, phil->ph, "has taken a fork");
		eating_process(phil);


	}

 //mutex locklar yerleştirilip eat sleep e yönlendirelecek.
 //actionların yazdırılması için bir tane fonksiyon oluştur uygun argümanla ile.
}

int	eating_process(t_philo *phil)
{
	if (ph_control)
		print_text(phil->info, present(), phil->ph, "is eating");
	while (ph_control)
		if (phil->info->eat_time + phil->last_action <= present())
			{
				phil->last_action = present();
				phil->death_time = present() + phil->info->die_time;


			}
}

void	print_text(t_data *info, long long time, int num, char *str)
{
	pthread_mutex_lock(&(info->text));
	if (ph_control)//eğer ölürse ??
		printf("%lld philosopher %d %s", (time - info->beginnig), num, str);
	pthread_mutex_unlock(&(info->text));
}

void	death_check(void *ph_struct)
{

}
