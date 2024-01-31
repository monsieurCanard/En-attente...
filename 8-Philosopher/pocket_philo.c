/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pocket_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:34:25 by anthony           #+#    #+#             */
/*   Updated: 2024/01/31 18:35:15 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    pocket_philo(char **argv)
{
    usleep(atoi(argv[2]) * 1000);
    printf("Philo [%d] is dead\n", 1);
    exit(0);
}