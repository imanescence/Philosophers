/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:34:50 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/09/11 14:55:31 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdatomic.h>
# include <limits.h>
# include <stdio.h>
# include <sys/time.h>

# define MALLOC_FAILED "Memory allocation failed !\n"
# define THREAD_FAILED "Thread creation failed !\n"
# define MUTEX_FAILED "Mutex creation failed !\n"
# define INVALID_ARG "All values must contain only positive digits !\n"
# define OVERFLOW_ERROR "You reached the INT MAX or more !\n"
# define MIN_PHILO "You must provide a minimum of 1 philosopher \n"
# define MIN_NB_MEAL "At least one meal please !\n"
# define OVERFLOW -1
# define FORK 1
# define EATING 2
# define SLEEPING 3
# define DEATH 4
# define THINKING 5
# define ENOUGH_MEAL 6 
# define FREE_MUTEX 1
# define FREE_THREADS 2
# define FREE_STRUCT 3
# define STOP 1
# define CONTINUE 0

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				l_fork;
	int				r_fork;
	pthread_t		dead_check;
	atomic_int		nb_meals;
	atomic_size_t	last_meal;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				die;
	int				eat;
	int				sleep;
	int				meal_goal;
	int				eat_enough;
	atomic_int		stop;
	atomic_size_t	init;
	pthread_mutex_t	display;
	pthread_mutex_t	death;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_data;

// ****************    PARSING    ****************

int		parsing(int argc, char **argv, int i);

//            ------- utils ---------
int		ft_strisdigit(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_atol(const char *str);

// ************   INITIALIZATIONS    **************

int		init_structs(t_data *data);
int		init_mutex(t_data *data);
int		init_thread(t_data *data);
void	forks_dispatcher(t_data *data);
int		data_init(t_data *data, char **argv);

// ************   PHILO'S ROUTINE   ***************

void	*ft_routine(void *param);
void	meal_time(t_philo *philo);
int		meal_check(t_data *data);
void	death_checker(t_philo *philo);

//             ------ utils -------
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
void	action_displayer(t_philo *philo, int flag, size_t init);
void	ft_putnbr(long nb, long base, char *strbase);
int		ft_putchar(int c);
int		ft_putstr(char *str);

// ************    FREE HANDLING   ***************

void	free_handler(void **ptr, t_data *data, int n, int flag);
void	free_threads(t_data *data, int n);

#endif
