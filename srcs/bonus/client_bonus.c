/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:42:08 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/04 09:25:53 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/ft_printf.h"
#include "../../includes/minitalk_bonus.h"

char	*g_str;

void	char_to_byte(char c, int pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		--i;
	}
}

void	sig_handler(int signum)
{
	static int	i;

	if (signum == SIGUSR1)
		++i;
	if (i == my_strlen(g_str))
		ft_printf("MESSAGE SEND PERFECTLY :)\n");
}

int	main(int ac, char **av)
{
	int			pid;
	int			i;
	char		*str;
	t_sigaction	action;

	if (has_an_error(ac, av))
		exit(1);
	pid = my_atoi(av[1]);
	str = av[2];
	g_str = av[2];
	i = -1;
	action.sa_handler = sig_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	while (str[++i])
		char_to_byte(str[i], pid);
	char_to_byte(str[i], pid);
	return (0);
}
