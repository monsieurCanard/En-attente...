/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:28:54 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/01 17:28:32 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_struct(t_list ***philo, char **argv, int *is_dead, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		(*philo)[i] = malloc(sizeof(t_list));
		if (!(*philo)[i])
			return ;
		(*philo)[i]->start_time = get_time_of_the_day();
		(*philo)[i]->index = i + 1;
		(*philo)[i]->is_dead = is_dead;
		(*philo)[i]->is_eating = get_time_of_the_day();
		(*philo)[i]->time_to_die = ft_atoi(argv[2]);
		(*philo)[i]->nb_philo = j;
		(*philo)[i]->end_eat = 0;
		(*philo)[i]->t_eat = ft_atoi(argv[3]);
		(*philo)[i]->t_sleep = ft_atoi(argv[4]);
		(*philo)[i]->time_stamp = 0;
		i++;
	}
	return ;
}

void	init_data(t_list ***philo, int argc, char **argv, int *is_dead)
{
	int	i;
	int	j;

	j = ft_atoi(argv[1]);
	i = 0;
	*philo = malloc(sizeof(t_list *) * j);
	if (!*philo)
		exit(-1);
	init_struct(philo, argv, is_dead, j);
	while (i < j)
	{
		if (argc == 6)
			(*philo)[i]->nb_eat = ft_atoi(argv[5]);
		else
			(*philo)[i]->nb_eat = -1;
		i++;
	}
	return ;
}
