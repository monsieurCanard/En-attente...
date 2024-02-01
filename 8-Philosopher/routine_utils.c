/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:03:20 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/01 17:06:59 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_eating(t_list *philo)
{
	while (get_time_of_the_day() <= philo->end_eat)
	{
		if (verif_dead(philo) == 1)
		{
			pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(philo->fork_right);
			return (1);
		}
	}
	return (0);
}
