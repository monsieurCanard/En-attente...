/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:58:22 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/30 19:17:01 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	while (1)
	{
		if (philo->index % 2 == 0)
		{
			pthread_mutex_lock(philo->fork_left);
			pthread_mutex_lock(philo->fork_right);
			print_forks(philo);
			pthread_mutex_lock(philo->is_eating_mutex);
			philo->is_eating = get_time_of_the_day();
			printf("is_eating = %lld\n", philo->is_eating);
			philo->end_eat = philo->is_eating + philo->t_eat;
			print_eating(philo);
			pthread_mutex_unlock(philo->is_eating_mutex);
			while (get_time_of_the_day() < philo->end_eat)
			{
			}
			pthread_mutex_unlock(philo->fork_right);
			pthread_mutex_unlock(philo->fork_left);
			}
			else
			{
				pthread_mutex_lock(philo->fork_right);
				pthread_mutex_lock(philo->fork_left);
				print_forks(philo);
				print_eating(philo);
				pthread_mutex_lock(philo->is_eating_mutex);
				philo->is_eating = get_time_of_the_day();
				printf("is_eating = %lld\n", philo->is_eating);
				philo->end_eat = philo->is_eating + philo->t_eat;
				pthread_mutex_unlock(philo->is_eating_mutex);
				while (get_time_of_the_day() < philo->end_eat)
				{
				}
				pthread_mutex_unlock(philo->fork_left);
				pthread_mutex_unlock(philo->fork_right);
			}
		pthread_mutex_lock(philo->is_dead_mutex);
		if (*(philo->is_dead) == 1)
		{
			pthread_mutex_unlock(philo->is_dead_mutex);
			break;
		}
			pthread_mutex_unlock(philo->is_dead_mutex);
			philo->start_sleep = get_time_of_the_day();
			philo->end_sleep = philo->start_sleep + philo->t_sleep;
			print_sleeping(philo);
			while (get_time_of_the_day() <= philo->end_sleep)
			{
		}
		verif_dead(philo);
		printf("%lld Philo [%d] is thinking\n",
			print_time(philo->start_time), philo->index);
	}
	//TODO Free les mutex
	//TODO Free les threads
	//TODO Free la structure
	return (0);
}

