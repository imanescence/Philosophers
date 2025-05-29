/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:30:05 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/09/07 14:57:54 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_threads(t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

void	free_handler(void **ptr, t_data *data, int n, int flag)
{
	int	i;

	i = 0;
	if (flag == FREE_STRUCT)
	{
		free(*ptr);
		*ptr = NULL;
	}
	if (flag == FREE_MUTEX || flag == FREE_THREADS)
	{
		if (flag == FREE_THREADS)
			n = data->nb_philo + 2;
		while (i < n)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
	if (flag == FREE_THREADS)
		free_threads(data, data->nb_philo);
	free(*ptr);
	*ptr = NULL;
}
