/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:25:28 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/20 07:45:12 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	send_char(pid_t pid, char c)
{
	size_t			i;
	unsigned char	mask;	
	int				ret;

	i = sizeof(char) * (size_t)CHAR_BIT;
	mask = 1 << (i - 1);
	while (i > 0)
	{
		if (!(mask & c))
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		usleep(100);
		if (ret < 0)
			return (false);
		mask = mask >> 1;
		i --;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

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
	while (*argv[2])
	{
		if (!send_char(server_pid, *argv[2]))
		{
			ft_putstr_fd(2, "Error: The message couldn't reach the server in its entirety.\n");
			return (1);
		}
		argv[2]++;
	}
	return (0);
}
