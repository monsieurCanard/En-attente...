/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:49:14 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/26 16:41:04 by Monsieur_Ca      ###   ########.fr       */
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
		philo[i]->start_thread = get_time_of_the_day();
		index = pthread_create(&thread[i], NULL, routine, (void *)philo[i]);
		if (index)
		{
			printf("Error creating thread\n");
			exit (-1);
		}
		printf("Thread [%d] created\n", i);
		i++;
	}
	return ;
}
