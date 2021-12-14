/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:31:48 by crondeau          #+#    #+#             */
/*   Updated: 2021/12/14 15:00:13 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_kill(int pid, int sig, char **argv)
{
	if (pid == 0 || kill(pid, sig) != 0)
	{
		write(2, "Error PID\n", 10);
		free(*argv);
		exit(1);
	}
}

void otherfunction(int pid, char *argv)
{
	static char *message = 0;
	static int s_pid = 0;
	static int i = 7;
	static int j = 0;

	if (pid != 0)
		s_pid = pid;
	if (argv != 0)
		message = strdup(argv);
	if (!message)
		exit(0);
	if (message[j] & 1 << i--)
		ft_kill(s_pid, SIGUSR2, &message);
	else
		ft_kill(s_pid, SIGUSR1, &message);
	if (i < 0)
	{
		i = 7;
		j++;
	}
	if (message[j] == '\0')
	{
		free(message);
		message = NULL;
	}
}

void	signal_handler(int sig)
{
	(void)sig;
	otherfunction(0, 0);
}

int	main(int argc, char **argv)
{
	int pid;
	
	if (argc != 3)
	{
		write (2, "Error: ./client PID string\n", 27);
		return (0);
	}
	pid = atoi(argv[1]);
	signal(SIGUSR1, &signal_handler);
	otherfunction(pid, argv[2]);
	while (1)
	{
		pause();
	}
	return (0);
}