/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:07:55 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/26 18:15:26 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	int					nb_philo;
	int					dead;
	int					t_die;
	int					t_eat;
	long long			start_eat;
	long long			end_eat;
	long long			start_think;
	long long			end_think;
	long long			start_sleep;
	long long			end_sleep;
	long long			start_thread;
	int					t_sleep;
	long long			time_stamp;
	int					index;
	int					nb_eat;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
}	t_list;

//Initialisation
void		init_data(t_list **philo, int argc, char **argv);
void		init_threads(t_list **philo, pthread_t *thread);
void		*routine(void *arg);
void		init_mutex_forks(t_list **philo);

// Time
long long	get_time_of_the_day(void);
void		get_time(t_list **philo, int index);
long long	print_time(long long start_time);

//Print
void		print_forks(t_list *philo);
void		print_eating(t_list *philo);
void		print_sleeping(t_list *philo);
void		print_thinking(t_list *philo);

	// Utils
	int ft_atoi(const char *str);
int			verif_dead(t_list *philo);
#endif