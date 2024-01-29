/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:05:23 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/29 19:42:09 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_list			**philo;
	pthread_t		*thread;
	int				i;
	int				is_dead;
	// pthread_mutex_t	fork_left;
	// pthread_mutex_t	fork_right;
	i = 0;
	is_dead = 0;
	if (argc < 5)
		return (0);
	philo = malloc(sizeof(t_list *) * ft_atoi(argv[1]));
	if (!philo)
		return (0);
	thread = malloc(sizeof(pthread_t) * (ft_atoi(argv[1]) * 2));
	if (!thread)
		return (free(philo), 0);
	printf("Malloc done\n");
	init_data(&philo, argv, &is_dead);
	init_mutex_forks(philo);
	init_mutex_ressource(philo, argv);
	init_threads(philo, thread);
	while (i < ft_atoi(argv[1]) * 2)
	{
		if (pthread_join(thread[i], NULL) != 0)
		{
			write(1, "Error joining thread\n", 21);
		}
		if (pthread_join(thread[philo[0] -> nb_philo + i], NULL) != 0)
		{
			write(1, "Error joining monitor thread\n", 29);
		}
		i++;	
	}
	// mister_free(philo);
	return (0);
}
