/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:05:23 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/02 14:47:18 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_list			**philo;
	pthread_t		*thread;
	int				is_dead;

	is_dead = 0;
	if (argc < 5)
		return (0);
	verif_arg(argc, argv);
	if (ft_atoi(argv[1]) == 1)
		pocket_philo(argv);
	thread = malloc(sizeof(pthread_t) * (ft_atoi(argv[1]) * 2));
	if (!thread)
		return (0);
	init_data(&philo, argc, argv, &is_dead);
	init_mutex_forks(philo);
	init_mutex_ressource(philo);
	init_mutex_ressource2(philo);
	init_mutex_ressource3(philo);
	init_threads(philo, thread);
	free_all_middle(philo, thread);
	return (0);
}
