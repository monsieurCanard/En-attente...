/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:27:10 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/28 11:07:19 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void free_philo(t_list *philo)
{
    if (philo != NULL)
    {
        if (philo->fork_left != NULL)
        {
            pthread_mutex_destroy(philo->fork_left);
            free(philo->fork_left);
        }
        if (philo->fork_right != NULL)
        {
            pthread_mutex_destroy(philo->fork_right);
            free(philo->fork_right);
        }
        free(philo);
    }
}

void free_all(t_list **philo)
{
	int i;

	i = 0;
	while (i < philo[0]->nb_philo)
	{
		free_philo(philo[i]);
		i++;
	}
	free(philo);
	pthread_exit(NULL);
	exit (0);
}