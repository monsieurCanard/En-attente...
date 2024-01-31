/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:52:39 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/31 16:31:29 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex_forks(t_list **philo)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
	if (!forks)
		return ; //TODO : free all
	i = 0;
	while (i < philo[0]->nb_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		// printf("Fork [%d] created\n", i);
		i++;
	}
	i = 0;
	while (i < philo[0]->nb_philo)
	{
		philo[i]->fork_left = &forks[i];
		if (i == philo[0]->nb_philo - 1)
			philo[i]->fork_right = &forks[0];
		else
			philo[i]->fork_right = &forks[(i + 1)];
		i++;
	}
	return ;
}
