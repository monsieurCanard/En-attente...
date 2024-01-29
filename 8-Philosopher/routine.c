/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:58:22 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/29 18:31:31 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->is_dead_mutex);
		if (philo->is_dead)
		{
			pthread_mutex_unlock(&philo->is_dead_mutex);
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&philo->is_dead_mutex);
		if (philo->index % 2 == 0)
		{
			pthread_mutex_lock(philo->fork_left);
			print_forks(philo);
			pthread_mutex_lock(philo->fork_right);
			print_forks(philo);
			print_eating(philo);
		}
		else
		{			
			pthread_mutex_lock(philo->fork_right);
			print_forks(philo);
			pthread_mutex_lock(philo->fork_left);
			print_forks(philo);
		}
		pthread_mutex_lock(philo->eat_mutex);
		philo->start_eat = get_time_of_the_day();
		print_eating(philo);
		philo->end_eat = philo->start_eat + philo->t_eat;
		pthread_mutex_unlock(philo->eat_mutex);
		while(get_time_of_the_day() < philo->end_eat)
		{
		}
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);





		
		print_sleeping(philo);
		philo->start_sleep = get_time_of_the_day();
		philo->end_sleep = philo->start_sleep + philo->t_sleep;
		print_sleeping(philo);
		while(get_time_of_the_day() < philo->end_sleep)
		{

		}
		printf("%lld Philo [%d] is thinking\n",
			print_time(philo->start_thread), philo->index);
	}
	//TODO Free les mutex
	//TODO Free les threads
	//TODO Free la structure
	return (0);
}