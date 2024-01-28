/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:53 by monsieurc         #+#    #+#             */
/*   Updated: 2024/01/28 11:05:28 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *monitor(void *arg)
{
    t_list *philo = (t_list *)arg;
    while (1)
    {
        if (philo->start_eat + philo->t_die == get_time_of_the_day())
        {
            printf("%lld Philo [%d] is dead\n",
                print_time(philo->start_thread), philo->index);
            philo->dead = 1;
            break;
        }
    }
    return NULL;
}