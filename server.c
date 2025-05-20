/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:14:14 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/20 16:01:01 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bit(int sig, siginfo_t *info, void *context)
{
	static t_byte	received_char = (t_byte){0, 0};
	pid_t			client_pid;

	(void)context;
	client_pid = info->si_pid;
	received_char.byte <<= 1;
	if (sig == SIGUSR2)
		received_char.byte |= 1;
	received_char.curr_bit ++;
	kill(client_pid, SIGUSR1);
	if (received_char.curr_bit == sizeof(char) * CHAR_BIT)
	{
		write(1, &received_char.byte, 1);
		received_char.byte = 0;
		received_char.curr_bit = 0;
		kill(client_pid, SIGUSR2);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = receive_bit;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("SERVER PID: %d\n", pid);
	while (true)
		sleep(1);
	return (0);
}
