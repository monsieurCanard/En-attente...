/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:53 by monsieurc         #+#    #+#             */
/*   Updated: 2024/01/29 19:35:01 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	philo_is_dead(t_list **philo)
// {
// 	printf("%lld Philo [%d] is dead\n",
// 				print_time(get_time_of_the_day(), philo->index_mutex));
// 	pthread_mutex_lock(philo->is_dead_mutex);
// 	philo->is_dead_mutex = 1;
// 	pthread_mutex_unlock(philo->is_dead_mutex);
// }
void	*monitor(void *arg)
{
	t_list		*philo;
	long long	start_eat;
	long long	time_to_die;
	int			index;

	philo = (t_list *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->is_eating_mutex);
		pthread_mutex_lock(&philo->time_to_die_mutex);
		pthread_mutex_lock(&philo->index_mutex);		
		if (philo->is_eating + philo->time_to_die == get_time_of_the_day())
			break;
		pthread_mutex_unlock(&philo->is_eating_mutex);
		pthread_mutex_unlock(&philo->index_mutex);
		pthread_mutex_unlock(&philo->time_to_die_mutex);
	}
	printf("%lld Philo [%d] is dead\n",
				print_time(get_time_of_the_day(), philo->index));
	pthread_mutex_lock(philo->is_dead_mutex);
	philo->is_dead = 1;
	pthread_mutex_unlock(philo->is_dead_mutex);
	// philo_is_dead(philo);
	return ;
}
