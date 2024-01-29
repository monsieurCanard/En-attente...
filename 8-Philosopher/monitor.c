/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:53 by monsieurc         #+#    #+#             */
/*   Updated: 2024/01/29 14:34:17 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_list	*philo;
	long long	start_eat;

	philo = (t_list *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->eat_mutex);
		start_eat = philo->start_eat;
		pthread_mutex_unlock(philo->eat_mutex);
		if (philo->start_eat + philo->t_die == get_time_of_the_day())
		{
			printf("%lld Philo [%d] is dead\n",
				print_time(philo->start_thread), philo->index);
			pthread_mutex_lock(&philo->is_dead_mutex);
			philo->is_dead = 1;
			pthread_mutex_unlock(&philo->is_dead_mutex);
			free_all(&philo);
		}
	}
	return (NULL);
}
