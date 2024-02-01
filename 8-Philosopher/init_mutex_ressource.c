/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_ressource.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:03:30 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/01 17:01:21 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex_ressource2(t_list **philo)
{
	int					i;
	pthread_mutex_t		*is_dead;
	pthread_mutex_t		*is_eating;

	i = -1;
	is_dead = malloc(sizeof(pthread_mutex_t));
	if (!is_dead)
		return ;
	pthread_mutex_init(is_dead, NULL);
	is_eating = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
	if (!is_eating)
		return ;
	while (++i < philo[0]->nb_philo)
		pthread_mutex_init(&is_eating[i], NULL);
	i = -1;
	while (++i < philo[0]->nb_philo)
	{
		philo[i]->is_dead_mutex = is_dead;
		philo[i]->is_eating_mutex = &is_eating[i];
	}
	return ;
}

void	init_mutex_ressource3(t_list **philo)
{
	pthread_mutex_t	*index;
	int				i;

	i = -1;
	index = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
	if (!index)
		return ;
	while (++i < philo[0]->nb_philo)
		pthread_mutex_init(&index[i], NULL);
	i = -1;
	while (++i < philo[0]->nb_philo)
		philo[i]->index_mutex = &index[i];
	return ;
}

void	init_mutex_ressource(t_list **philo)
{
	int					i;
	pthread_mutex_t		*time_to_die;
	pthread_mutex_t		*nb_eat;

	i = -1;
	time_to_die = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
	if (!time_to_die)
		return ;
	nb_eat = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
	if (!nb_eat)
		return ;
	while (++i < philo[0]->nb_philo)
	{
		pthread_mutex_init(&time_to_die[i], NULL);
		pthread_mutex_init(&nb_eat[i], NULL);
	}
	i = -1;
	while (++i < philo[0]->nb_philo)
	{
		philo[i]->time_to_die_mutex = &time_to_die[i];
		philo[i]->nb_eat_mutex = &nb_eat[i];
	}
	return ;
}
