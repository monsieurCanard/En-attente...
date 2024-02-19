/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:07:25 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/01 14:39:21 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	waiting_end_monitor(t_list **philo, pthread_t *thread)
{
	int	i;

	i = -1;
	while (++i < philo[0]->nb_philo)
	{
		if (pthread_join(thread[i + philo[0]->nb_philo], NULL))
			printf("Error joining thread\n");
	}
}

void	waiting_end_thread(t_list **philo, pthread_t *thread)
{
	int	i;

	i = -1;
	while (++i < philo[0]->nb_philo)
	{
		if (pthread_join(thread[i], NULL))
			printf("Error joining thread\n");
	}
}
