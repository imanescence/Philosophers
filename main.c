/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:27:04 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/09/07 15:05:01 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wrong_nb_of_args(void)
{
	ft_putstr_fd("Error ! You must to provide the number ", 2);
	ft_putstr_fd("of philosophers, time to die, eat, and sleep ! ", 2);
	ft_putstr_fd("No more or less arguments !\n", 2);
}

int	data_init(t_data *data, char **argv)
{
	if (ft_atol(argv[1]) == OVERFLOW)
		return (-1);
	data->nb_philo = ft_atol(argv[1]);
	if (ft_atol(argv[2]) == OVERFLOW)
		return (-1);
	data->die = ft_atol(argv[2]);
	if (ft_atol(argv[3]) == OVERFLOW)
		return (-1);
	data->eat = ft_atol(argv[3]);
	if (ft_atol(argv[4]) == OVERFLOW)
		return (-1);
	data->sleep = ft_atol(argv[4]);
	if (argv[5])
	{
		if (ft_atol(argv[5]) == OVERFLOW)
			return (-1);
		if (ft_atol(argv[5]) == 0)
		{
			ft_putstr_fd(MIN_NB_MEAL, 2);
			return (-1);
		}
		data->meal_goal = ft_atol(argv[5]);
	}
	data->stop = 0;
	return (0);
}

int	parsing(int argc, char **argv, int i)
{
	if (argc != 6 && argc != 5)
	{
		wrong_nb_of_args();
		return (1);
	}
	while (i <= 4 && argv[i])
	{
		if (ft_strisdigit(argv[i]) == 1)
		{
			ft_putstr_fd(INVALID_ARG, 2);
			return (1);
		}
		i++;
	}
	if (argv[5])
	{
		if (ft_strisdigit(argv[i]) == 1)
		{
			ft_putstr_fd(INVALID_ARG, 2);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parsing(argc, argv, 1) == 1)
		return (1);
	if (data_init(&data, argv) == OVERFLOW)
		return (1);
	if (data.nb_philo == 0)
	{
		ft_putstr_fd(MIN_PHILO, 2);
		return (1);
	}
	if (init_structs(&data) == 1)
		return (-1);
	free_handler((void **)&data.forks, &data, data.nb_philo, FREE_THREADS);
	free_handler((void **)&data.philo, NULL, 0, FREE_STRUCT);
	return (0);
}
