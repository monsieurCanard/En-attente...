/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:05:23 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/29 14:35:12 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_list			**philo;
	pthread_t		*thread;
	int				i;
	// pthread_mutex_t	fork_left;
	// pthread_mutex_t	fork_right;
	i = 0;
	if (argc < 5)
		return (0);
	philo = malloc(sizeof(t_list *) * ft_atoi(argv[1]));
	if (!philo)
		return (0);
	thread = malloc(sizeof(pthread_t) * (ft_atoi(argv[1]) * 2));
	if (!thread)
		return (0);
	printf("Malloc done\n");
	init_data(&philo, argc, argv);
	init_mutex_forks(philo);
	init_mutex_ressource(philo);
	init_threads(philo, thread);
	while (1)
	{
		while (i < philo[0]->nb_philo)
		{
			if (pthread_join(thread[i], NULL) == 0)
				free_all(philo);
			// else if (philo[i]->dead == 1)
			// 	free_all(philo);
			i++;
		}
	}
	free_all(philo);
	return (0);
}
