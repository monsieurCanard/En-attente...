/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:05:23 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/26 10:52:24 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_list			**philo;
	pthread_t		*thread;
	// pthread_mutex_t	fork_left;
	// pthread_mutex_t	fork_right;

	if (argc < 5)
		return (0);
	philo = malloc(sizeof(t_list *) * ft_atoi(argv[1]));
	if (!philo)
		return (0);
	thread = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (!thread)
		return (0);
	init_data(philo, argc, argv);
	init_mutex_forks(philo);
	init_threads(philo, thread);
	pthread_exit(NULL);
	return (0);
}
