/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:42:46 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/21 14:24:09 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/ft_printf.h"
#include "../../includes/minitalk.h"

void	sig_handler(int signum)
{
	static int	counter;
	static char	c;
	int			nb;

	if (SIGUSR1 == signum)
		nb = 1;
	else if (SIGUSR2 == signum)
		nb = 0;
	c = nb + (c << 1);
	counter++;
	if (8 == counter)
	{
		ft_printf("%c", c);
		counter = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("WELCOME TO THE SERVER :)\n");
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
	}
	return (0);
}
