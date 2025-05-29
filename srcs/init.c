/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:32 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/09/07 15:05:17 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_dispatcher(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].r_fork = i;
		if (i == (data->nb_philo - 1))
		{
			data->philo[i].l_fork = 0;
			break ;
		}
		data->philo[i].l_fork = i + 1;
		i++;
	}
}

int	init_structs(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (data->philo == NULL)
	{
		ft_putstr_fd(MALLOC_FAILED, 2);
		return (1);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo + 1);
	if (data->forks == NULL)
	{
		free_handler((void **)&data->philo, NULL, 0, FREE_STRUCT);
		ft_putstr_fd(MALLOC_FAILED, 2);
		return (1);
	}
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		i++;
	}
	if (init_mutex(data) == 1)
		return (1);
	return (0);
}

int	forks_mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			ft_putstr_fd(MUTEX_FAILED, 2);
			free_handler((void **)&data->forks, data, i, FREE_MUTEX);
			free_handler((void **)&data->forks, NULL, 0, FREE_STRUCT);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	if (forks_mutex_init(data) != 0)
		return (1);
	if (pthread_mutex_init(&data->display, NULL) != 0)
	{
		ft_putstr_fd(MUTEX_FAILED, 2);
		free_handler((void **)&data->forks, data,
			data->nb_philo + 1, FREE_MUTEX);
		free_handler((void **)&data->forks, NULL, 0, FREE_STRUCT);
		return (1);
	}
	if (pthread_mutex_init(&data->death, NULL) != 0)
	{
		ft_putstr_fd(MUTEX_FAILED, 2);
		free_handler((void **)&data->forks, data,
			data->nb_philo + 2, FREE_MUTEX);
		free_handler((void **)&data->forks, NULL, 0, FREE_STRUCT);
		return (1);
	}
	forks_dispatcher(data);
	if (init_thread(data) == 1)
		return (1);
	return (0);
}

int	init_thread(t_data *data)
{
	int	i;

	i = 0;
	data->init = get_current_time();
	while (i < data->nb_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].last_meal = get_current_time();
		if (pthread_create
			(&data->philo[i].thread, NULL, ft_routine, &(data->philo[i])) != 0)
		{
			ft_putstr_fd(THREAD_FAILED, 2);
			free_handler((void **)&data->philo, data, i, FREE_THREADS);
			free_handler((void **)&data->forks, NULL, 0, FREE_STRUCT);
			return (1);
		}
		i++;
	}
	death_checker(data->philo);
	return (0);
}
