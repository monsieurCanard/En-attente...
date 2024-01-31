/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:05:23 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/31 18:37:13 by anthony          ###   ########.fr       */
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
	void 			*retval;

	i = -1;
	verif_arg(argc, argv);
	j = ft_atoi(argv[1]);
	is_dead = 0;
	if (argc < 5)
		return (0);
	if (j == 1)
		pocket_philo(argv);
	thread = malloc(sizeof(pthread_t) * (ft_atoi(argv[1]) * 2));
	if (!thread)
		return (free(philo), 0);
	(init_data(&philo, argc, argv, &is_dead), init_mutex_forks(philo));
	(init_mutex_ressource(philo), init_threads(philo, thread));
	i = -1;
	while(++i < j)
	{
		if (pthread_join(thread[i + philo[0]->nb_philo], &retval))
    		printf("Error joining thread\n");
		else if (retval != NULL)
    		printf("Thread returned %d\n", *(int *)retval);
	}
	i = -1;
	while(++i < j)
	{
		if (pthread_join(thread[i], &retval))
    		printf("Error joining thread\n");
		else if (retval != NULL)
    		printf("Thread returned %d\n", *(int *)retval);
	}
	
	return (0);
}
