/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:18:52 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/01 12:00:10 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	while (1)
	{
		philo->time_stamp = get_time_of_the_day();
		printf("time = %lld\n", philo->time_stamp);
	}
	return (NULL);
}
