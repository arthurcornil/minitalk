/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:14:14 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/20 07:48:22 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bit(int sig)
{
	static t_byte	received_char = (t_byte){0, 0};

	received_char.byte <<= 1;
	if (sig == SIGUSR2)
		received_char.byte |= 1;
	received_char.curr_bit ++;
	if (received_char.curr_bit == sizeof(char) * CHAR_BIT)
	{
		write(1, &received_char.byte, 1);
		received_char.byte = 0;
		received_char.curr_bit = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	unsigned char		received_char;
	struct sigaction	sa;

	(void)received_char;
	pid = getpid();
	sa.sa_handler = receive_bit;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	received_char = 0;
	printf("SERVER PID: %d\n", pid);
	while (true)
		sleep(1);
	return (0);
}
