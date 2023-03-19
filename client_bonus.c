/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:52 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/03/19 02:40:12 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	ft_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("Received successfully!\n");
}

int	main(int ac, char **str)
{
	pid_t	pid;
	char	*s;

	if (ac == 3)
	{
		signal(SIGUSR1, ft_handler);
		pid = (pid_t)ft_atoi(str[1]);
		if (pid > 0)
		{
			s = str[2];
			while (*s)
				send_char(pid, *s++);
			send_char(pid, 0);
		}
		else
			ft_putstr("\033[91mThe server pid is Invalid.\n\033[0m");
	}
	else
		ft_putstr("\033[91mError: Try Agin.\n\033[0m");
	return (0);
}
