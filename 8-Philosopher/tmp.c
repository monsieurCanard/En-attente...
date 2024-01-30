

// philo[i]->is_dead_mutex = malloc(sizeof(pthread_mutex_t));
// if (!philo[i]->is_dead_mutex)
// 	return ; //TODO : free all
// pthread_mutex_init(philo[i]->is_dead_mutex, NULL);

// philo[i]->is_dead = &is_dead

// philo[i]->time_to_die_mutex = malloc(sizeof(pthread_mutex_t));
// if (!philo[i]->time_to_die_mutex)
// 	return ; //TODO : free all
// pthread_mutex_init(&philo[i]->time_to_die_mutex, NULL);

// philo[i]->is_eating_mutex = malloc(sizeof(pthread_mutex_t));
// if (!philo[i]->is_eating_mutex)
// 	return ; //TODO : free all
// pthread_mutex_init(&philo[i]->is_eating_mutex, NULL);

// philo[i]->is_safe_mutex = malloc(sizeof(pthread_mutex_t));
// if (!philo[i]->is_safe_mutex)
// 	return ; //TODO : free all
// pthread_mutex_init(&philo[i]->is_safe_mutex, NULL);
// philo[i]->is_safe_mutex = 0;

// philo[i]->nb_eat_mutex = malloc(sizeof(pthread_mutex_t));
// if (!philo[i]->nb_eat_mutex)
// 	return ; //TODO : free all
// pthread_mutex_init(&philo[i]->nb_eat_mutex, NULL);
// if (argc == 6)
// 	philo[i]->nb_eat_mutex = atoi(argv[5]); //TODO Verifie si le nb est positif
// else
// 	philo[i]->nb_eat_mutex = -1;
// i++;