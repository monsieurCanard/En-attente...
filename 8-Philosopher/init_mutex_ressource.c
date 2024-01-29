/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_ressource.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:03:30 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/29 19:36:26 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex_ressource(t_list **philo, char **argv)
{
	int					i;
	pthread_mutex_t		*is_dead;
	i = 0;

	is_dead = malloc(sizeof(pthread_mutex_t));
	if (!is_dead)
		return ; //TODO : free all
	pthread_mutex_init(&is_dead, NULL);
	is_dead = 0;
	while (i < philo[0]->nb_philo)
	{
		philo[i]->index_mutex = malloc(sizeof(pthread_mutex_t));
		if (!philo[i]->index_mutex)
			return ; //TODO : free all
		pthread_mutex_init(&philo[i]->index_mutex, NULL);
		
		philo[i]->is_dead_mutex = malloc(sizeof(pthread_mutex_t));
		if (!philo[i]->is_dead_mutex)
			return ; //TODO : free all
		pthread_mutex_init(&philo[i]->is_dead_mutex, NULL);
		philo[i]->dead = &is_dead
		
		philo[i]->time_to_die_mutex = malloc(sizeof(pthread_mutex_t));
		if (!philo[i]->time_to_die_mutex)
			return ; //TODO : free all
		pthread_mutex_init(&philo[i]->time_to_die_mutex, NULL);
		
		philo[i]->is_eating_mutex = malloc(sizeof(pthread_mutex_t));
		if (!philo[i]->is_eating_mutex)
			return ; //TODO : free all
		pthread_mutex_init(&philo[i]->is_eating_mutex, NULL);
		
		philo[i]->is_safe_mutex = malloc(sizeof(pthread_mutex_t));
		if (!philo[i]->is_safe_mutex)
			return ; //TODO : free all
		pthread_mutex_init(&philo[i]->is_safe_mutex, NULL);
		philo[i]->is_safe_mutex = 0;
		
		philo[i]->nb_eat_mutex = malloc(sizeof(pthread_mutex_t));
		if (!philo[i]->nb_eat_mutex)
			return ; //TODO : free all
		pthread_mutex_init(&philo[i]->nb_eat_mutex, NULL);
		if (argc == 6)
			philo[i]->nb_eat_mutex = atoi(argv[5]); //TODO Verifie si le nb est positif 
		else
			philo[i]->nb_eat_mutex = -1;
		i++;
	}
	return ;
}