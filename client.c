/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:48:13 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/03/20 18:03:26 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char s)
{
	int	i;

	i = 8;
	while ((--i) >= 0)
	{
		if (s & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
}

int	main(int ac, char **str)
{
	pid_t	pid;
	char	*s;

	if (ac == 3)
	{
		if (is_all_digit(str[1]) == 1)
		{
			pid = (pid_t)ft_atoi(str[1]);
			if (pid > 0)
			{
				s = str[2];
				while (*s)
					send_char(pid, *s++);
			}
			else
				ft_putstr("\033[91mThe server PID is Invalid.\n\033[0m");
		}
		else
			ft_putstr("\033[91mThe PID contains not just numbers.\n\033[0m");
	}
	else
		ft_putstr("\033[91mError: Try Agin.\n\033[0m");
	return (0);
}
