/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:14:14 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/18 21:08:27 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig(pid_t sig)
{
	printf("%d\n", sig);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("%d\n", pid);
	while (true)
	{
		sleep(1);
		signal(SIGUSR1, handle_sig);
	}
	return (0);
}
