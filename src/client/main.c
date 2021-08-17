/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:11:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/17 18:34:31 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

static void	send_str(pid_t pid, char *str)
{
	char	bits;
	char	bit;

	while (*str)
	{
		bits = 0;
		while (bits < 8)
		{
			bit = 0;
			bit = *str & (1 << bits);
			if (bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1000);
			bits++;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		send_str(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
