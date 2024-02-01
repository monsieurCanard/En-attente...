/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_permission_fork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:44:41 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/01 12:24:48 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philo.h"

// void	init_permission_fork(t_list **philo)
// {
// 	pthread_mutex_t	*left_perm;
// 	pthread_mutex_t	*right_perm;
// 	int				i;

// 	i = 0;
// 	left_perm = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
// 	if (!left_perm)
// 		return ; //TODO : free all
// 	right_perm = malloc(philo[0]->nb_philo * sizeof(pthread_mutex_t));
// 	if (!right_perm)
// 		return ; //TODO : free all
// 	while (i < philo[0]->nb_philo)
// 	{
// 		pthread_mutex_init(&left_perm[i], NULL);
// 		pthread_mutex_init(&right_perm[i], NULL);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < philo[0]->nb_philo)
// 	{
// 		philo[i]->left_perm = &left_perm[i];
// 		if (i == philo[0]->nb_philo - 1)
// 			philo[i]->right_perm = &right_perm[0];
// 		else
// 			philo[i]->right_perm = &right_perm[i + 1];
// 		i++;
// 	}
// 	return ;
// }
