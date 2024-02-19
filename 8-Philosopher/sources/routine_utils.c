/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:03:20 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/19 11:44:33 by anthony          ###   ########.fr       */
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

int	philo_is_sleeping(t_list *philo)
{
	while (get_time_of_the_day() <= philo->end_sleep)
	{
		if (verif_dead(philo) == 1)
		{
			return (1);
		}
	}
	return (0);
}

void	ft_usleep(int time)
{
	long int	tmp_time;

	tmp_time = get_time_of_the_day();
	while (get_time_of_the_day() - tmp_time < time)
		usleep(time / 10);
}
