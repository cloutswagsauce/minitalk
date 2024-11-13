/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:41:25 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/13 17:57:45 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"


void handle_signal(int sig)
{
	printf("signal received!!");

}
int main(void)
{
	signal(SIGUSR1, handle_signal);
	printf("server running with pid: %d\n", getpid());
	printf("-----------------\n");
	
}