/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:05:23 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/30 17:40:45 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_list			**philo;
	pthread_t		*thread;
	int				i;
	int				j;
	int				is_dead;

	i = 0;
	j = ft_atoi(argv[1]);
	is_dead = 0;
	if (argc < 5)
		return (0);
	philo = malloc(sizeof(t_list *) * ft_atoi(argv[1]));
	if (!philo)
		return (0);
	thread = malloc(sizeof(pthread_t) * (ft_atoi(argv[1]) * 2));
	if (!thread)
		return (free(philo), 0);
	init_data(&philo, argc, argv, &is_dead);
	init_mutex_forks(philo);
	init_mutex_ressource(philo);
	init_threads(philo, thread);
	while(i < j)
	{
		if (pthread_join(thread[i], NULL))
		{
			printf("Error joining thread\n");
			// handle error
		}
		if (pthread_join(thread[i + philo[0]->nb_philo], NULL))
		{
			printf("Error joining monitor thread\n");
			// handle error
		}
		i++;
	}
	// mister_free(philo);
	return (0);
}
