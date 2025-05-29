/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:51:41 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/09/11 15:14:56 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(200);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

// Opti print version

/*void	sleep_eat_think_display(t_philo *philo, int flag, size_t time)
{
	if (flag == EATING)
	{
		ft_putnbr(time, 10, "0123456789");
		write (1, " ", 1);
		ft_putnbr(philo->id, 10, "0123456789");
		ft_putstr(" is eating\n");
	}
	if (flag == SLEEPING)
	{
		ft_putnbr(time, 10, "0123456789");
		write (1, " ", 1);
		ft_putnbr(philo->id, 10, "0123456789");
		ft_putstr(" is sleeping\n");
	}
	if (flag == THINKING)
	{
		ft_putnbr(time, 10, "0123456789");
		write (1, " ", 1);
		ft_putnbr(philo->id, 10, "0123456789");
		ft_putstr(" is thinking\n");
	}
}

void	action_displayer(t_philo *philo, int flag, size_t init)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->display);
	time = get_current_time() - init;
	if (philo->data->stop == 0)
	{
		if (flag == FORK)
		{
			ft_putnbr(time, 10, "0123456789");
			write (1, " ", 1);
			ft_putnbr(philo->id, 10, "0123456789");
			ft_putstr(" has taken a fork\n");
		}
		if (flag == EATING)
			sleep_eat_think_display(philo, EATING, time);
		if (flag == SLEEPING)
			sleep_eat_think_display(philo, SLEEPING, time);
		if (flag == THINKING)
			sleep_eat_think_display(philo, SLEEPING, time);
	}
	pthread_mutex_unlock(&philo->data->display);
}*/

// Cute print version

void	action_displayer(t_philo *philo, int flag, size_t init)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->display);
	time = get_current_time() - init;
	if (philo->data->stop == 0)
	{
		if (flag == FORK)
			printf("\x1b[38;5;159m%zu %d has taken a fork ❪🍴❫\n",
				time, philo->id);
		if (flag == EATING)
			printf("\x1b[38;5;212m%zu %d is eating        [🍝]\n",
				time, philo->id);
		if (flag == SLEEPING)
			printf("\x1b[38;5;122m%zu %d is sleeping     【🧸💤】\n",
				time, philo->id);
		if (flag == THINKING)
			printf("\x1b[38;5;229m%zu %d is thinking      [💭] \n",
				time, philo->id);
	}
	pthread_mutex_unlock(&philo->data->display);
}
