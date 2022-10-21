/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:57:34 by coder             #+#    #+#             */
/*   Updated: 2022/10/13 19:24:40 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int	sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	set_signals(struct sigaction *act, struct sigaction *act_2)
{
	act->sa_handler = &sig_handler;
	sigaction(SIGINT, act, NULL);
	act_2->sa_handler = SIG_IGN;
	sigaction(SIGQUIT, act_2, NULL);
	sigaction(SIGTSTP, act_2, NULL);
}
