/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pocket_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:34:25 by anthony           #+#    #+#             */
/*   Updated: 2024/02/19 12:12:33 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pocket_philo(char **argv)
{
	usleep(ft_atoi(argv[2]) * 1000);
	printf("%lld %d is dead\n", get_time_of_the_day(), 1);
	exit(0);
}
