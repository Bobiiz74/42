/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:11:45 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/11 18:54:19 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <sys/time.h>

typedef struct s_fork
{	
	pthread_mutex_t	mutex;
	int				taken;
}t_fork;

typedef struct s_philo
{
	pthread_t		thread_id;
	pthread_t		thread_death_id;
	int				id;
	int				eat_count;
	long int		last_meal;
	t_fork			*left_fork;
	t_fork			*right_fork;
	struct s_info	*info;
}t_philo;

typedef struct s_info
{	
	pthread_mutex_t	write_mut;
	pthread_mutex_t	dead;
	int				stop;
	long int		start_t;
	int				number_of_philosophers;
	int				number_of_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	t_fork			*forks;
	t_philo			*philos;
}t_info;

// main.c
int		main(int argc, char **argv);
void	check_all_eat(t_info *info);
void	free_all(t_info *info);
void	ft_exit(t_info *info);
int		numeric(char **argv, int i, int j);

//routine.c
void	*routine_philo(void *arg);
void	activity(t_info *info, t_philo *philo);
void	write_status(char *str, t_philo *philo, t_info *info);
void	sleep_think(t_philo *philo, t_info *info);
void	one_philo(int time_to_die);

//init_struct.c
t_philo	*init_struct_philo(t_info *info);
t_fork	*init_struct_fork(t_info *info);
t_info	*init_struct_info(int ac, char **av);

//usleep.c
void	ft_usleep(long int time_in_ms, t_info *info, t_philo *philo);
long int	actual_time(void);

//utils.c
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);

//check.c
void	is_dead(t_info *info, t_philo *philo);

#endif
