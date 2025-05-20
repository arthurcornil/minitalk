/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:25:28 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/20 16:13:12 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

struct s_ack_status 
{
	sig_atomic_t	bit_ack;
	sig_atomic_t	byte_ack;
};

volatile struct s_ack_status	g_ack_status;

bool	send_char(pid_t pid, char c)
{
	size_t			i;
	unsigned char	mask;	
	int				ret;

	i = sizeof(char) * (size_t)CHAR_BIT;
	mask = 1 << (i - 1);
	while (i > 0)
	{
		g_ack_status.bit_ack = false;
		if (!(mask & c))
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret < 0)
			return (false);
		while (!g_ack_status.bit_ack)
			pause();
		mask = mask >> 1;
		i --;
	}
	g_ack_status.byte_ack = false;
	while (!g_ack_status.byte_ack)
		pause();
	return (true);
}

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd(1, "\nGot bit ack\n");
		g_ack_status.bit_ack = true;
	}
	else
	{
		ft_putstr_fd(1, "\nGot byte ack\n");
		g_ack_status.byte_ack = true;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		printf("Usage: client [SERVER_PID] [MESSAGE]\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd(2, "Error: Invalid PID.\n");
		return (1);
	}
	sa.sa_handler = handle_ack;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (*argv[2])
	{	
		g_ack_status.bit_ack = false;
		if (!send_char(server_pid, *argv[2]))
		{
			ft_putstr_fd(2, "Error: The message couldn't reach the server in its entirety.\n");
			return (1);
		}
		argv[2]++;
	}
	return (0);
}
