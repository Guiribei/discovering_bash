/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:13:00 by coder             #+#    #+#             */
/*   Updated: 2022/10/10 20:39:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*prompt;
	struct sigaction	act;

	if (argc == 0 || !argv[0])
		return (1);
	set_signals(&act);
	set_env(envp);
	while (1)
	{
		prompt = set_prompt("minishell$");
		free(prompt);
		if (!prompt)
		{
			free(prompt);
			write(1, "\n", 1);
			exit(127);
		}
	}
	free(prompt);
	return (0);
}
