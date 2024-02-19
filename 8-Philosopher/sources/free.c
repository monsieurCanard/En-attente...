/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:27:10 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/19 11:23:50 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_philo(t_list *philo)
{
	if (philo != NULL)
	{
		if (philo->fork_left != NULL)
		{
			pthread_mutex_destroy(philo->fork_left);
			free(philo->fork_left);
			philo->fork_left = NULL;
		}
		if (philo != NULL)
			free(philo);
	}
}

void	free_all(t_list **philo)
{
	int	i;

	i = 0;
	while (i < philo[0]->nb_philo)
	{
		free_philo(philo[i]);
		i++;
	}
	free(philo);
	pthread_exit(NULL);
	exit (0);
}

static void	free_element_struct(t_list **philo)
{
	free((*philo)[0].fork_left);
	free((*philo)[0].is_eating_mutex);
	free((*philo)[0].is_dead_mutex);
	free((*philo)[0].index_mutex);
	free((*philo)[0].nb_eat_mutex);
	free((*philo)[0].time_to_die_mutex);
}

void	free_all_middle(t_list **philo, pthread_t *thread)
{
	int	i;
	int	nb_philo;

	nb_philo = philo[0]->nb_philo;
	waiting_end_thread(philo, thread);
	waiting_end_monitor(philo, thread);
	free (thread);
	i = -1;
	while (++i < nb_philo)
	{
		pthread_mutex_destroy(philo[i]->is_eating_mutex);
		pthread_mutex_destroy(philo[i]->is_dead_mutex);
		pthread_mutex_destroy(philo[i]->index_mutex);
		pthread_mutex_destroy(philo[i]->nb_eat_mutex);
		pthread_mutex_destroy(philo[i]->time_to_die_mutex);
		pthread_mutex_destroy(philo[i]->fork_left);
		pthread_mutex_destroy(philo[i]->fork_right);
	}
	free_element_struct(philo);
	i = -1;
	while (++i < nb_philo)
		free(philo[i]);
	free(philo);
	exit (0);
}
