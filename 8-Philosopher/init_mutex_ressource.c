/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_ressource.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:03:30 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/29 14:44:02 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex_ressource(t_list **philo)
{
	int					i;

	i = 0;
	while (i < philo[0]->nb_philo)
	{
		philo[i]->eat_mutex = malloc(sizeof(pthread_mutex_t));
		if (!philo[i]->eat_mutex)
			return ;
		pthread_mutex_init(philo[i]->eat_mutex, NULL);
		philo[i]->fork_right = malloc(sizeof(pthread_mutex_t));
		if (!philo[i]->fork_right)
			return ;
		pthread_mutex_init(philo[i]->fork_right, NULL);
		pthread_mutex_init(&philo[i]->is_dead_mutex, NULL);
		i++;
	}
	return ;
}