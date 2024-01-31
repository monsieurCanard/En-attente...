/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:27:39 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/31 18:30:31 by anthony          ###   ########.fr       */
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

