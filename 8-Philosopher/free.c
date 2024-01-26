/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:27:10 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/26 18:46:19 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_list *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].nb_philo)
	{
		pthread_mutex_destroy(&philo[i].fork_left);
		pthread_mutex_destroy(&philo[i].fork_right);
		i++;
	}
	free(philo);
	exit (0) ;
}
