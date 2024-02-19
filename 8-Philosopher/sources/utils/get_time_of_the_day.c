/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_of_the_day.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:46:17 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/19 10:32:11 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_of_the_day(void)
{
	struct timeval	time;
	long long		time_stamp;

	gettimeofday(&time, NULL);
	time_stamp = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_stamp);
}

long long	print_time(long long start_time)
{
	return (get_time_of_the_day() - start_time);
}

void	get_time(t_list **philo, int index)
{
	philo[index]->time_stamp = get_time_of_the_day();
	return ;
}
