/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:31:09 by crondeau          #+#    #+#             */
/*   Updated: 2021/12/14 14:46:28 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb > 0)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void signal_handler(int sig, siginfo_t *info, void *context) // va traduire chaque caractère en binaire et envoyer un par un les 0 et les 1 
{
	(void)sig;
	(void)context;
	static char r = 0;
	static char byte_pos = 0;

	if (sig == SIGUSR2) // si c'est un 1, on envoi le singal SIGUSR1 à server
		r += 1 << (7 - byte_pos);
	byte_pos++;
	if (byte_pos == 8)
	{
		write(1, &r, 1); // sinon, on envoi SIGUSR2
		byte_pos = 0;
		r = 0;
	}
	if (kill(info->si_pid, SIGUSR1)) // protection
		write(1, "PID CLIENT ERROR\n", 17);
}


int main (void)
{
	struct sigaction        sa;

	write(1, "PID: ", 5);  // ("PID: %d\n", getpid()); on affiche le pid du serveur
	ft_putnbr(getpid());
	write(1, "\n", 1);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1) // laisse tourner le processus pour pouvoir lui envoyer des signaux
		pause();
	return (0);
}