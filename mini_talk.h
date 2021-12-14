/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:29:20 by crondeau          #+#    #+#             */
/*   Updated: 2021/12/14 12:00:29 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <unistd.h>
# include <sys/types.h> 

void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_atoi(const char *nbr);
void	ft_putchar(char c);
void	otherfunction(int );
void	signal_handler(int sig);

//pid_t getpid (void); 
//pid_t getppid (void);