/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:39:43 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/03/20 02:41:17 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
