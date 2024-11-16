/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:41:25 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/15 19:02:47 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../minitalk.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void handle_signal(int sig, siginfo_t *info, void *content)
{
	printf("signal received!!");
}

	
	


int main(void)
{
	struct sigaction s_action;

	printf("server running with pid: %d\n", getpid());
	printf("-----------------\n");

	s_action.sa_sigaction = handle_signal;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, 0);
	sigaction(SIGUSR2, &s_action, 0);
	while (1)
	{
		sleep(1);
	}
	return (0);

	
}