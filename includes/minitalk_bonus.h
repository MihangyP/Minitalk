/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:09:01 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/04 07:36:03 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>

typedef struct sigaction	t_sigaction;

int	my_atoi(const char *nptr);
int	has_an_error(int ac, char **av);
int	my_strlen(const char *str);

#endif
