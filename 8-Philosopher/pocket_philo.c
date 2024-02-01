/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pocket_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:34:25 by anthony           #+#    #+#             */
/*   Updated: 2024/02/01 17:30:30 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pocket_philo(char **argv)
{
	usleep(ft_atoi(argv[2]) * 1000);
	printf("Philo [%d] is dead\n", 1);
	exit(0);
}
