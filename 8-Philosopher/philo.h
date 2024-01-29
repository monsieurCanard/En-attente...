/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:07:55 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/29 19:40:29 by anthony          ###   ########.fr       */
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

# define ERROR_MSG "Error: Thread not join correctly\n"

typedef struct s_list
{
	pthread_mutex_t		index_mutex;
	int					index;
	pthread_mutex_t		*is_dead_mutex;
	int					*is_dead;
	pthread_mutex_t		is_safe_mutex;
	int					is_safe;
	int					nb_philo;
	pthread_mutex_t		time_to_die_mutex;
	int					time_to_die;
	int					t_eat;
	pthread_mutex_t		is_eating_mutex;
	long long			is_eating;
	long long			end_eat;
	long long			start_think;
	long long			end_think;
	long long			start_sleep;
	long long			end_sleep;
	int					t_sleep;
	long long			time_stamp;
	pthread_mutex_t		nb_eat_mutex;
	int					nb_eat;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;

}	t_list;

//Initialisation
void		init_data(t_list ***philo, int argc, char **argv, int *is_dead);
void		init_threads(t_list **philo, pthread_t *thread);
void		*routine(void *arg);
void		init_mutex_forks(t_list **philo);
void		init_mutex_ressource(t_list **philo, char **argv, int *is_dead);

	// Monitor
void		*monitor(void *arg);

// Time
long long	get_time_of_the_day(void);
void		get_time(t_list **philo, int index);
long long	print_time(long long start_time);

//Print
void		print_forks(t_list *philo);
void		print_eating(t_list *philo);
void		print_sleeping(t_list *philo);
void		print_thinking(t_list *philo);

//Free
void		free_all(t_list **philo);

// Utils
int			ft_atoi(const char *str);

#endif