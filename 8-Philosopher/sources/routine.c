/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:58:22 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/19 11:44:22 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_list *philo)
{
	if (verif_dead(philo) == 1)
		return (1);
	pthread_mutex_lock(philo->fork_left);
	if (verif_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	pthread_mutex_lock(philo->fork_right);
	(print_forks(philo), print_eating(philo));
	pthread_mutex_lock(philo->is_eating_mutex);
	philo->is_eating = get_time_of_the_day();
	philo->end_eat = philo->is_eating + philo->t_eat;
	pthread_mutex_unlock(philo->is_eating_mutex);
	philo_is_eating(philo);
	if (verif_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	print_sleeping(philo);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	return (0);
}

static int	sleep_philo(t_list *philo)
{
	if (verif_dead(philo) == 1)
		return (1);
	philo->start_sleep = get_time_of_the_day();
	philo->end_sleep = philo->start_sleep + philo->t_sleep;
	ft_usleep(philo->t_sleep);
	if (verif_dead(philo) == 1)
		return (1);
	print_thinking(philo);
	return (0);
}

void	*routine(void *arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	if (philo->index % 2 == 0)
		ft_usleep(philo->t_sleep / 10);
	while (1)
	{
		if (eat(philo) == 1)
			return (0);
		pthread_mutex_lock(philo->nb_eat_mutex);
		philo->nb_eat--;
		if (philo->nb_eat == 0)
		{
			pthread_mutex_unlock(philo->nb_eat_mutex);
			return (0);
		}
		pthread_mutex_unlock(philo->nb_eat_mutex);
		if (verif_dead(philo) == 1)
			return (0);
		if (sleep_philo(philo) == 1)
			return (0);
	}
	return (0);
}
