/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:23:17 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/02/19 10:28:07 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_forks(t_list *philo)
{
	printf("%lld %d has taken a fork\n",
		print_time(philo->start_time), philo->index);
	printf("%lld %d has taken a fork\n",
		print_time(philo->start_time), philo->index);
}

void	print_eating(t_list *philo)
{
	printf("%lld %d is eating\n",
		print_time(philo->start_time), philo->index);
}

void	print_sleeping(t_list *philo)
{
	printf("%lld %d is sleeping\n",
		print_time(philo->start_time), philo->index);
}

void	print_thinking(t_list *philo)
{
	printf("%lld %d is thinking\n",
		print_time(philo->start_time), philo->index);
}
