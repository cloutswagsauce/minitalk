/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:41:22 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/15 18:07:55 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../minitalk.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void str_to_bin(char *str, int pid)
{
	int	i;


	while (*str)
	{
		i = 8;
		while (i--)
		{
			if (*str >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		}
		str++;
	}
	i = 8;
	while (i--)
		kill(pid, SIGUSR1);
	
}
int main(int argc, char **argv)
{
	int server_pid;
	if (argc != 3)
	{
		write(1, "specify string", 14);
	}
	server_pid = atoi(argv[1]);
	str_to_bin(argv[2], server_pid);
	return (0);

}