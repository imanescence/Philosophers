/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:36:53 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/04/02 18:34:00 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atol(const char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		nb = nb * 10;
		nb = nb + (str[i++] - '0');
	}
	if (nb >= INT_MAX)
	{
		ft_putstr_fd(OVERFLOW_ERROR, 2);
		return (OVERFLOW);
	}
	return ((int)nb);
}
