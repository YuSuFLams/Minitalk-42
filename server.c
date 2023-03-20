/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:57:48 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/03/20 18:03:04 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_server(int sig, siginfo_t *siginfo, void *str)
{
	static int	i;
	static int	cli_pid;
	static char	s;

	(void)str;
	if (cli_pid != siginfo->si_pid)
	{
		i = 0;
		s = 0;
		cli_pid = siginfo->si_pid;
	}
	i++;
	s = s << 1 | (sig - SIGUSR1);
	if (i == 8)
	{
		ft_putchar(s);
		s = 0;
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	s_usr;

	pid = (int)getpid();
	ft_putstr("Your PID:\t");
	ft_putnbr(pid);
	ft_putchar('\n');
	s_usr.sa_flags = SA_SIGINFO;
	s_usr.sa_sigaction = ft_server;
	sigaction(SIGUSR1, &s_usr, NULL);
	sigaction(SIGUSR2, &s_usr, NULL);
	while (1)
		pause();
	return (0);
}
