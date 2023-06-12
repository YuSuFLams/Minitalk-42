/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:38:43 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/03/23 14:26:10 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		ft_putstr("(null)");
	while (*s)
		ft_putchar(*s++);
}

int	ft_atoi(const char *s)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= (-1);
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
	{
		n = n * 10 + *s - '0';
		s++;
	}
	return ((int )n * sign);
}

void	ft_putnbr(int nbr)
{
	long	n;

	n = nbr;
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	if (n < 0)
	{
		ft_putchar('-');
		n *= (-1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	is_all_digit(char *s)
{
	int	i;

	i = 0;
	if (*(s + i) == '+')
		i++;
	if (*(s + i) == '-')
		i++;
	while (*(s + i))
	{
		if (*(s + i) < '0' || *(s + i) > '9')
			return (0);
		i++;
	}
	return (1);
}
