/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:42:08 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/21 14:29:00 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/ft_printf.h"
#include "../../includes/minitalk.h"

void	char_to_byte(char c, int pid)
{
	int	i;

	i = 7;
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

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*str;

	if (has_an_error(ac, av))
		exit(1);
	pid = my_atoi(av[1]);
	str = av[2];
	i = -1;
	while (str[++i])
		char_to_byte(str[i], pid);
	char_to_byte(str[i], pid);
	return (0);
}
