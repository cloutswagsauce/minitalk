/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:41:25 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/16 17:48:50 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"



void handle_signal(int sig, siginfo_t *info, void *context)
	{
		
	(void)(context);
	(void)(info);
	static char c;
	static int bit_pos;
	
	if (sig == SIGUSR2)
		c |= (1 << bit_pos);
	else if (sig == SIGUSR1)
		c &= ~(1 << bit_pos);
	bit_pos++;
	if (bit_pos == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bit_pos = 0;
	}
		
	}


int main(void)
{
	struct sigaction s_action;
	
	ft_memset(&s_action, 0, sizeof(s_action));

	printf("server running with pid: %d\n", getpid());
	printf("-----------------\n");

	s_action.sa_sigaction = handle_signal;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, 0);
	sigaction(SIGUSR2, &s_action, 0);
	while (1)
	{
		pause();
	}
	return (0);

	
}