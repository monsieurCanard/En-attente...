/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:37:33 by anthony           #+#    #+#             */
/*   Updated: 2024/01/31 18:44:42 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	verif_arg(int argc, char **argv)
{
	if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0 || atoi(argv[3]) < 0 || atoi(argv[4]) < 0 || (argv[5] && atoi(argv[5]) < 0))
		exit(printf("Error: argument must be greater than 0\n"));
	else if (argc > 6)
		exit(printf("Error: too many arguments\n"));
	else
		return ;
}