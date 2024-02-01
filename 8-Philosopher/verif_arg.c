/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:37:33 by anthony           #+#    #+#             */
/*   Updated: 2024/02/01 17:28:44 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	verif_arg(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0
		|| (argv[5] && ft_atoi(argv[5]) < 0))
		exit(printf("Error: argument must be greater than 0\n"));
	else if (argc > 6)
		exit(printf("Error: too many arguments\n"));
	else
		return ;
}
