/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:41:22 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/18 11:19:53 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../minitalk.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void received_messaged(int sig)
{
	if (sig)
		write(1, "message received by server!", 27);
	
}
void	str_to_bin(char *str, int pid)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(1000);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	//struct sigaction	s_action;
	int					server_pid;

	//ft_memset(&s_action, 0, sizeof(s_action));
	//s_action.sa_sigaction = received_messaged;
	signal(SIGUSR1, received_messaged);

	if (argc != 3)
	{
		write(1, "invalid args", 12);
		return (0);
	}
	server_pid = atoi(argv[1]);
	str_to_bin(argv[2], server_pid);
	return (0);
}
