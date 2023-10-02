/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:40:16 by fracerba          #+#    #+#             */
/*   Updated: 2023/02/23 11:40:18 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_action(int sig)
{
	static int	rev = 0;

	if (sig == SIGUSR1)
		rev++;
	else if (sig == SIGUSR2)
	{
		ft_printf("%i\n", rev);
		exit(0);
	}
}

void	client_aux(int pid)
{
	int	j;

	j = 8;
	while (j)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		j--;
	}
}

void	c_kill(int pid, char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i])
	{
		j = 8;
		c = str[i];
		while (j)
		{
			j--;
			if ((c >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		i++;
	}
	client_aux(pid);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (0);
	i = ft_strlen(argv[2]);
	if (i == 0)
		return (0);
	ft_printf("Inviati: %i\n", i);
	ft_printf("Ricevuti: ");
	signal(SIGUSR1, client_action);
	signal(SIGUSR2, client_action);
	i = ft_atoi(argv[1]);
	c_kill(i, argv[2]);
	while (1)
		pause();
	return (0);
}
