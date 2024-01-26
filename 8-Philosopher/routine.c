/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:58:22 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/26 18:33:11 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	while (verif_dead(philo) == 0)
	{
		if (philo->index % 2 == 0)
		{
			verif_dead(philo);
			pthread_mutex_lock(philo->fork_left);
			print_forks(philo);
			pthread_mutex_lock(philo->fork_right);
			print_forks(philo);
			print_eating(philo);
		}
		else
		{
			verif_dead(philo);
			pthread_mutex_lock(philo->fork_right);
			print_forks(philo);
			pthread_mutex_lock(philo->fork_left);
			print_forks(philo);
			print_eating(philo);
		}
		philo->start_eat = get_time_of_the_day();
		philo->end_eat = philo->start_eat + philo->t_eat;
		verif_dead(philo);
		while (philo->time_stamp < philo->end_eat)
		{
			verif_dead(philo);
			if (verif_dead(philo) == 1)
				return (0);
			philo->time_stamp = get_time_of_the_day();
		}
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		print_sleeping(philo);
		philo->start_sleep = get_time_of_the_day();
		philo->end_sleep = philo->start_sleep + philo->t_sleep;

		while (philo->time_stamp < philo->end_sleep)
		{
			if (verif_dead(philo) == 1)
				exit(0);
			philo->time_stamp = get_time_of_the_day();
		}

		
		printf("%lld Philo [%d] is thinking\n",
			print_time(philo->start_thread), philo->index);
	
	}
	//TODO Free les mutex
	//TODO Free les threads
	//TODO Free la structure
	return (0);
}