/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:23:17 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/30 17:30:19 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_forks(t_list *philo)
{
	printf("%lld Philo [%d] has taken a fork\n",
		print_time(philo->start_time), philo->index);
	printf("%lld Philo [%d] has taken a fork\n",
		print_time(philo->start_time), philo->index);
}

void	print_eating(t_list *philo)
{
	printf("%lld Philo [%d] is eating\n",
		print_time(philo->start_time), philo->index);
}

void	print_sleeping(t_list *philo)
{
	printf("%lld Philo [%d] is sleeping\n",
		print_time(philo->start_time), philo->index);
}

void	print_thinking(t_list *philo)
{
	printf("%lld Philo [%d] is thinking\n",
		print_time(philo->start_time), philo->index);
}
