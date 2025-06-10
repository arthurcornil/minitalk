/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:25:28 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/20 18:54:08 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t	g_bit_ack;

static void	send_char(pid_t pid, char c)
{
	size_t			i;
	unsigned char	mask;	
	int				ret;

	i = sizeof(char) * (size_t)CHAR_BIT;
	mask = 1 << (i - 1);
	while (i > 0)
	{
		g_bit_ack = 0;
		if (!(mask & c))
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret < 0)
		{
			ft_putstr_fd("Error: A bit could not reach the server.", 2);
			exit(EXIT_FAILURE);
		}
		while (!g_bit_ack)
			pause();
		mask = mask >> 1;
		i --;
	}
}

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		g_bit_ack = 1;
	else
		exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: client [SERVER_PID] [MESSAGE]\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Error: Invalid PID.\n", 2);
		return (1);
	}
	sa.sa_handler = handle_ack;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (*argv[2])
	{	
		send_char(server_pid, *argv[2]);
		usleep(10);
		argv[2]++;
	}
	send_char(server_pid, '\0');
	while(1)
		pause();
	return (0);
}
