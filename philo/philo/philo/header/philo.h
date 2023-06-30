/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomat <ktomat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:56:44 by ktomat            #+#    #+#             */
/*   Updated: 2023/06/13 11:22:09 by ktomat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

typedef struct s_times
{
	unsigned long long				die_time;
	unsigned long long				eat_time;
	unsigned long long				sleep_time;
	unsigned long long				start_time;
	int								nbr_of_meal_needed;
	t_philo							*philo;
}				t_times;

typedef struct s_philo
{
	int						id;
	int						nbr_of_meal;
	unsigned long long		time_last_meal;
	pthread_mutex_t			fork;
	pthread_mutex_t			*next_fork;
	pthread_mutex_t			lst_meal;
	pthread_mutex_t			meal;
	pthread_t				thread;
	t_table					*table;
	t_times					*times;
}				t_philo;

typedef struct s_table
{
	int				status;
	int				philo_dead;
	int				nbr_philo;
	t_times			*times;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	status1;
}				t_table;

int						msg_error(char *str);
long int				ft_atoi(const char *str);
int						check_int(int ac, char **av);
int						check_args(int ac, char **av);

long long int			get_time_pass(unsigned long long start,
							unsigned long long end);
void					ms_sleep(unsigned long long milliseconde);
unsigned long long		get_actual_time(void);

void					free_philo(t_table *table);
void					destroy_mutex(t_table *table);
void					destroy_thread(t_table *table);

int						thread_start(t_table *table);

void					eat(t_philo *philo);
void					sleep1(t_philo *philo);
void					think(t_philo *philo);

void					supervisor(t_table *table);
int						death_checker(t_table *table);
int						meal_checker(t_table *table);

int						status_check(t_philo *philo);

#endif