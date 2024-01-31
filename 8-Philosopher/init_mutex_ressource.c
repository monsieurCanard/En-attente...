/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_ressource.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:03:30 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/31 14:47:54 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex_ressource(t_list **philo)
{
	int					i;
	pthread_mutex_t		*index;
	pthread_mutex_t		*is_dead;
	pthread_mutex_t		*is_safe;
	pthread_mutex_t		*time_to_die;
	pthread_mutex_t		*is_eating;
	pthread_mutex_t		*nb_eat;


	i = 0;
	is_dead = malloc(sizeof(pthread_mutex_t));
	if (!is_dead)
		return ; //TODO : free all
	
	pthread_mutex_init(is_dead, NULL);
	
	index = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
	if (!index)
		return ; //TODO : free all

	is_safe = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
	if (!is_safe)
		return ; //TODO : free all

	time_to_die = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
	if (!time_to_die)
		return ; //TODO : free all

	is_eating = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
	if (!is_eating)
		return ; //TODO : free all
	
	nb_eat = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
	if (!nb_eat)
		return ; //TODO : free all

	while (i < philo[0]->nb_philo)
	{
		pthread_mutex_init(&index[i], NULL);
		pthread_mutex_init(&is_safe[i], NULL);
		pthread_mutex_init(&time_to_die[i], NULL);
		pthread_mutex_init(&is_eating[i], NULL);
		pthread_mutex_init(&nb_eat[i], NULL);
		i++;
	}
	i = 0;
	while (i < philo[0]->nb_philo)
	{
		philo[i]->index_mutex = &index[i];
		philo[i]->is_dead_mutex = is_dead;
		philo[i]->is_safe_mutex = &is_safe[i];
		philo[i]->time_to_die_mutex = &time_to_die[i];
		philo[i]->is_eating_mutex = &is_eating[i];
		philo[i]->nb_eat_mutex = &nb_eat[i];
		i++;
	}
	return ;
}