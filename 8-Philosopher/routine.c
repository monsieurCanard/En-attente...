/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:58:22 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/01 17:17:19 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat_impair(t_list *philo)
{
	if (verif_dead(philo) == 1)
		return (1);
	pthread_mutex_lock(philo->fork_right);
	if (verif_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	pthread_mutex_lock(philo->fork_left);
	if (verif_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	(print_forks(philo), print_eating(philo));
	pthread_mutex_lock(philo->is_eating_mutex);
	philo->is_eating = get_time_of_the_day();
	philo->end_eat = philo->is_eating + philo->t_eat;
	pthread_mutex_unlock(philo->is_eating_mutex);
	if (philo_is_eating(philo) == 1)
		return (1);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	return (0);
}

static int	eat_pair(t_list *philo)
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
	if (verif_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	(print_forks(philo), pthread_mutex_lock(philo->is_eating_mutex));
	philo->is_eating = get_time_of_the_day();
	philo->end_eat = philo->is_eating + philo->t_eat;
	print_eating(philo);
	pthread_mutex_unlock(philo->is_eating_mutex);
	if (philo_is_eating(philo) == 1)
		return (1);
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
	print_sleeping(philo);
	if (verif_dead(philo) == 1)
		return (1);
	usleep(philo->t_sleep * 1000);
	if (verif_dead(philo) == 1)
		return (1);
	print_thinking(philo);
	return (0);
}

static int	dispatch_philo(t_list *philo)
{
	if (philo->index % 2 == 0)
	{
		if (eat_pair(philo) == 1)
			return (1);
	}
	else
	{
		if (eat_impair(philo) == 1)
			return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	while (1)
	{
		if (dispatch_philo(philo) == 1)
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
		if (verif_dead(philo) == 1)
			return (0);
	}
	return (0);
}
