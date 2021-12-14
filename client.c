/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:31:48 by crondeau          #+#    #+#             */
/*   Updated: 2021/12/13 15:12:39 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include <stdlib.h>
#include <unistd.h>

void otherfunction(int )
{
	static char *message;
	(void)sig;

	
	j = 0;
	while (argv[2][j])
	{
		a = argv[2][j];
		i = 6;
		while (i > -1)
		{
			if (a & 1 << i--)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
		}
		j++;
	}
}

void	signal_handler(int sig)
{

}

int	main(int argc, char **argv)
{
	int pid;
	char a;
	int i;
	int j;
	
	if (argc != 3)
	{
		return (0);
	}
	pid = atoi(argv[1]);
	signal(SIGUSR1, &signal_handler);
	j = 0;
	while (1)
	{
		pause();
	}
	return (0);
}