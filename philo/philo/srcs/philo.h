/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:56:44 by robin             #+#    #+#             */
/*   Updated: 2023/07/05 14:20:50 by robin            ###   ########.fr       */
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
typedef struct s_info	t_info;

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
	pthread_mutex_t			last_meal;
	pthread_mutex_t			meal;
	pthread_t				thread;
	t_info					*info;
	t_times					*times;
}				t_philo;

typedef struct s_info
{
	int				status;
	int				philo_dead;
	int				nbr_philo;
	t_times			*times;
	t_philo			*philo;
	pthread_mutex_t	write;
	pthread_mutex_t	status1;
}				t_info;

int						print_error(char *str);
long int				ft_atoi(const char *str);
int						check_int(int ac, char **av);
int						check_args(int ac, char **av);

long long int			get_time_pass(unsigned long long start,
							unsigned long long end);
void					ft_usleep(unsigned long long milliseconde);
unsigned long long		get_actual_time(void);

void					free_philo(t_info *info);
void					destroy_mutex(t_info *info);
void					destroy_thread(t_info *info);

int						thread_start(t_info *info);

void					eat(t_philo *philo);
void					sleep1(t_philo *philo);
void					think(t_philo *philo);

void					supervisor(t_info *info);
int						check_death(t_info *info);
int						check_meal(t_info *info);

int						status_check(t_philo *philo);

#endif