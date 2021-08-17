/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:11:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/17 18:47:43 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

static void	sig_event(int sig)
{
	static unsigned char	letter;
	static unsigned char	bits;

	if (bits < 8)
	{
		if (sig == SIGUSR1)
			letter |= 1 << bits;
		if (sig == SIGUSR2)
			letter &= ~(1 << bits);
		bits++;
	}
	if (bits == 8)
	{
		write(1, &letter, 1);
		letter = 0;
		bits = 0;
	}
}

static void	initialize_sigsystem(sigset_t *set)
{
	if (sigemptyset(set) == -1)
	{
		ft_putstr("Error: Cannot initialize empty set.\n");
		exit(0);
	}
	if (sigaddset(set, SIGUSR1) == -1)
	{
		ft_putstr("Error: Cannot add SIGUSR1 signal to set\n");
		exit(0);
	}
	if (sigaddset(set, SIGUSR2) == -1)
	{
		ft_putstr("Error: Cannot add SIGUSR2 signal to set\n");
		exit(0);
	}
	signal(SIGUSR1, sig_event);
	signal(SIGUSR2, sig_event);
}

static void	main_loop(void)
{
	sigset_t	set;

	initialize_sigsystem(&set);
	while (42)
	{
	}
}

int	main(void)
{
	char		*s_pid;

	s_pid = ft_itoa(getpid());
	ft_putstr("PID = ");
	ft_putstr(s_pid);
	ft_putstr('\n');
	free(s_pid);
	main_loop();
	return (0);
}
