/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:06:25 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/04 07:18:51 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/ft_printf.h"
#include "../../includes/minitalk.h"

int	my_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

static int	is_spaces(const char c)
{
	return (c == 32 || (c > 8 && c < 14));
}

int	my_atoi(const char *nptr)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (is_spaces(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (num * neg);
}

static int	is_digit(int c)
{
	return (c > 47 && c < 58);
}

int	has_an_error(int ac, char **av)
{
	int	i;

	if (ac != 3)
	{
		ft_printf("THIS PROGRAM TAKES 2 PARAMS: PID and MESSAGE\n");
		return (1);
	}
	i = -1;
	while (av[1][++i])
	{
		if (!is_digit(av[1][i]))
		{
			ft_printf("THE FIRST ARGUMENT MUST BE THE PID OF THE SERVER\n");
			return (1);
		}
	}
	return (0);
}
