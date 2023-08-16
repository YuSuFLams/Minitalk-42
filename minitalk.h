/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:40:12 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/08/16 16:57:56 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_atoi(const char *s);
void	ft_putnbr(int nbr);
int		is_all_digit(char *s);

#endif
