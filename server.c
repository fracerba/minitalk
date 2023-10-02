/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:40:28 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/23 11:40:30 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

unsigned char	server_aux(int sign, unsigned char c)
{
	unsigned char	a;

	a = c;
	if (sign == SIGUSR2)
		a |= 1;
	else
		a |= 0;
	return (a);
}

void	server_action(int sign, siginfo_t *sig, void *content)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static pid_t			pid = 0;

	(void)content;
	if (pid == 0)
		pid = sig->si_pid;
	c = server_aux(sign, c);
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == 0)
		{
			kill(pid, SIGUSR2);
			pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
		kill(pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sig;
	int					id;

	id = (int)getpid();
	ft_printf("Server PID: %i\n", id);
	sig.sa_sigaction = server_action;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
	return (0);
}
