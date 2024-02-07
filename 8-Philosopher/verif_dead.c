/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:27:39 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/07 12:48:25 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_dead(t_list *philo)
{
	pthread_mutex_lock(philo->is_dead_mutex);
	if (*philo->is_dead == 1)
	{
		pthread_mutex_unlock(philo->is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->is_dead_mutex);
	return (0);
}
