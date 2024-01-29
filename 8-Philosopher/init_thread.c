/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:49:14 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/29 19:23:49 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads(t_list **philo, pthread_t *thread)
{
	int	i;
	int	index;

	i = 0;
	while (i < philo[0]->nb_philo)
	{
		// pthread_mutex_lock(philo[i]->is_eating_mutex);
		philo[i]->is_eating_tmp = get_time_of_the_day();
		// pthread_mutex_unlock(philo[i]->is_eating_mutex);
		index = pthread_create(&thread[i], NULL, routine, (void *)philo[i]);
		if (index)
		{
			printf("Error creating thread\n");
			exit (-1);//TODO : free all
		}
		printf("Thread [%d] created\n", i);
		index = pthread_create(&thread[i + philo[0]->nb_philo], NULL, monitor, (void *)philo[i]);
		if (index)
		{
			printf("Error creating monitor thread\n");
			exit (-1);//TODO : free all
		}
		printf("Thread [%d] and monitor thread created\n", i);
		i++;
	}
	return ;
}
