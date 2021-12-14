/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:31:09 by crondeau          #+#    #+#             */
/*   Updated: 2021/12/14 11:58:49 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void signal_handler(int sig, siginfo_t *info, void *context) // va traduire chaque caractère en binaire et envoyer un par un les 0 et les 1 
{
	(void)sig;
	(void)context;
	static char r = 0;
	static char byte_pos = 0;

	if (sig == SIGUSR2) // si c'est un 1, on envoi le singal SIGUSR1 à server
		r += 1 << (6 - byte_pos);
	byte_pos++;
	if (byte_pos == 7)
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

	printf("PID: %d\n", getpid()); // on affiche le pid du serveur
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1) // laisse tourner le processus pour pouvoir lui envoyer des signaux
		pause();
	return (0);
}