/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:41:22 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/13 18:04:19 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"


int main(int argc, char **argv)
{
	ft_printf("client is running!\n");
	if (argc == 2)
	{
		kill(ft_atoi(argv[1]), SIGUSR1);

	}
	return (0);

}