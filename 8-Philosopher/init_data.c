/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:28:54 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/30 19:16:18 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_list ***philo, int argc, char **argv, int *is_dead)
{
	int	i;
	int	j;

	j = atoi(argv[1]);
	i = 0;
	*philo = malloc(sizeof(t_list*) * j);
	if (!*philo)
		exit(-1);
	while (i < j)
	{
		(*philo)[i] = malloc(sizeof(t_list));
		if (!(*philo)[i])
			exit(-1);
		(*philo)[i]->start_time = get_time_of_the_day();
		(*philo)[i]->index = i + 1;
		(*philo)[i]->is_dead = is_dead;
		(*philo)[i]->is_eating = 0;
		(*philo)[i]->is_safe = 0;
		(*philo)[i]->time_to_die = atoi(argv[2]);
		(*philo)[i]->nb_philo = j;
		(*philo)[i]->end_eat = get_time_of_the_day() + atoi(argv[2]);
		(*philo)[i]->t_eat = atoi(argv[3]);
		(*philo)[i]->t_sleep = atoi(argv[4]);
		(*philo)[i]->time_stamp = 0;
		if (argc == 6)
			(*philo)[i]->nb_eat = atoi(argv[5]);
		else
			(*philo)[i]->nb_eat = -1;
		i++;
	}
}
