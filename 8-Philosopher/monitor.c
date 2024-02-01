/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:53 by monsieurc         #+#    #+#             */
/*   Updated: 2024/02/01 12:05:18 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	verif_nb_eat(t_list *philo)
{
	if (philo->nb_eat == 0)
	{
		pthread_mutex_unlock(philo->nb_eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->nb_eat_mutex);
	return (0);
}

static int	verif_eat(t_list *philo)
{
	if (get_time_of_the_day() >= philo->is_eating + philo->time_to_die)
	{
		pthread_mutex_unlock(philo->is_eating_mutex);
		pthread_mutex_lock(philo->index_mutex);
		printf("%lld Philo [%d] is dead\n",
			print_time(philo->start_time), philo->index);
		pthread_mutex_unlock(philo->index_mutex);
		pthread_mutex_lock(philo->is_dead_mutex);
		*philo->is_dead = 1;
		pthread_mutex_unlock(philo->is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->is_eating_mutex);
	return (0);
}

void	*monitor(void *arg)
{
	t_list		*philo;

	philo = (t_list *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->nb_eat_mutex);
		if (verif_nb_eat(philo) == 1)
			return (0);
		if (verif_dead(philo) == 1)
			return (0);
		pthread_mutex_lock(philo->is_eating_mutex);
		if (verif_eat(philo) == 1)
			return (0);
	}
	return (0);
}
