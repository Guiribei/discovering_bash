/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:16:49 by coder             #+#    #+#             */
/*   Updated: 2022/10/19 14:47:46 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include "../libs/libft/libft.h"
#include <stdarg.h>

int		echo(char **str);
void	strclear(char **str);
void	strsclear(char **ptrs);
int		pwd(void);
char	*set_prompt(const char *name);
void	set_signals(struct sigaction *act, struct sigaction *act_2);
t_list	*set_env(char *envp[]);
int		builtin_env(t_list *env);
int		builtin_export(t_list *env, char *name);

#endif
