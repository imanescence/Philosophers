/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:14:10 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/09/07 15:45:09 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death_case(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death);
	philo->data->stop = STOP;
	printf("\x1b[41m\x1b[30m%zu %d died      𓆩🖤𓆪 ☠️  𓆩🖤𓆪 \n",
		get_current_time() - philo->data->init, philo->id);
	pthread_mutex_unlock(&philo->data->death);
}

void	death_checker(t_philo *philo)
{
	int	i;

	while (philo->data->stop == CONTINUE)
	{
		i = 0;
		philo->data->eat_enough = 0;
		while (i < philo->data->nb_philo && philo->data->stop == CONTINUE)
		{
			if (get_current_time() - philo[i].last_meal
				>= (size_t)philo->data->die)
				death_case(philo);
			if (philo->data->meal_goal > 0)
			{
				if (philo[i].nb_meals >= philo->data->meal_goal)
					philo->data->eat_enough++;
				if (philo->data->eat_enough == philo->data->nb_philo)
					philo->data->stop = STOP;
			}
			i++;
		}
	}
}

void	meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	action_displayer(philo, FORK, philo->data->init);
	if (philo->data->nb_philo == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
		ft_usleep(philo->data->die);
		action_displayer(&philo[0], DEATH, philo->data->init);
		philo->data->stop = STOP;
	}
	pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	action_displayer(philo, FORK, philo->data->init);
	action_displayer(philo, EATING, philo->data->init);
	philo->nb_meals += 1;
	ft_usleep(philo->data->eat);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
}

void	*ft_routine(void *param)
{
	t_philo	*philo;

	philo = param;
	philo->nb_meals = 0;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat / 2);
	while (philo->data->stop == CONTINUE)
	{
		meal_time(philo);
		philo->last_meal = get_current_time();
		action_displayer(philo, SLEEPING, philo->data->init);
		ft_usleep(philo->data->sleep);
		action_displayer(philo, THINKING, philo->data->init);
	}
	return (NULL);
}
