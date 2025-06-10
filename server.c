/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:14:14 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/20 18:57:03 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bit(int sig, siginfo_t *info, void *context)
{
	static t_byte	received_char = (t_byte){0, 0};

	(void)context;
	if (info->si_pid <= 0)
		return ;
	received_char.byte <<= 1;
	if (sig == SIGUSR2)
		received_char.byte |= 1;
	received_char.curr_bit ++;
	kill(info->si_pid, SIGUSR1);
	if (received_char.curr_bit == sizeof(char) * CHAR_BIT)
	{
		received_char.curr_bit = 0;
		if (received_char.byte == (char)0)
		{
			kill(info->si_pid, SIGUSR2);
			write(1, "\n", 1);
			return ;
		}
		write(1, &received_char.byte, 1);
		received_char.byte = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = &receive_bit;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("SERVER PID: %d\n", pid);
	while (true)
		pause();
	return (0);
}
