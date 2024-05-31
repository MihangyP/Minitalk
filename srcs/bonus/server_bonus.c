/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:42:46 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/04 09:33:31 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/ft_printf.h"
#include "../../includes/minitalk_bonus.h"

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	counter;
	static char	c;
	int			nb;

	(void)context;
	if (SIGUSR1 == signum)
		nb = 1;
	else if (SIGUSR2 == signum)
		nb = 0;
	c = nb + (c << 1);
	counter++;
	if (32 == counter)
	{
		ft_printf("%c", c);
		kill(info->si_pid, SIGUSR1);
		counter = 0;
		c = 0;
	}
}

int	main(void)
{
	t_sigaction	action;

	ft_printf("WELCOME TO THE SERVER :)\n");
	ft_printf("PID: %d\n", getpid());
	action.sa_sigaction = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
	}
	return (0);
}
