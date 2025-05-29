/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:03:56 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/09/11 15:04:47 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	ft_putnbr(long nb, long base, char *strbase)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb < base)
	{
		ft_putchar(strbase[nb]);
	}
	if (nb >= base)
	{
		ft_putnbr(nb / base, base, strbase);
		ft_putchar(strbase[nb % base]);
	}
}
