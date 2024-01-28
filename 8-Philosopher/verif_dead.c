/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:27:39 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/26 18:27:04 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_dead(t_list **philo)
{
	int	i;

	i = 0;
	while (i < philo[0]->nb_philo)
	{
		if (philo[i]->start_eat + philo[i]->t_die == get_time_of_the_day())
		{
			printf("%lld Philo [%d] is dead\n",
				print_time(philo[i]->start_thread), philo[i]->index);
			free_all(philo);
			return (1);
		}
		i++;
	}
	return (0);
}