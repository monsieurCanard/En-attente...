/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:27:10 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/01 16:59:17 by Monsieur_Ca      ###   ########.fr       */
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
		}
		if (philo->fork_right != NULL)
		{
			pthread_mutex_destroy(philo->fork_right);
			free(philo->fork_right);
		}
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

void	free_all_middle(t_list **philo, pthread_t *thread)
{
	int	i;
	int	nb_philo;

	nb_philo = philo[0]->nb_philo;
	waiting_end_thread(philo, thread);
	waiting_end_monitor(philo, thread);
	free (thread);
	i = -1;
	while (++i < philo[0]->nb_philo)
	{
		pthread_mutex_destroy(philo[i]->is_eating_mutex);
		pthread_mutex_destroy(philo[i]->is_dead_mutex);
		pthread_mutex_destroy(philo[i]->index_mutex);
		pthread_mutex_destroy(philo[i]->fork_left);
		pthread_mutex_destroy(philo[i]->nb_eat_mutex);
		pthread_mutex_destroy(philo[i]->time_to_die_mutex);
	}
	i = -1;
	while (++i < nb_philo)
		free_philo(philo[i]);
	free(philo);
	exit (0);
}
