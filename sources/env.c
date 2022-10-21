/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:25:43 by coder             #+#    #+#             */
/*   Updated: 2022/10/19 14:49:05 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*set_env(char *envp[])
{
	int		i;
	t_list	*env;
	
	i = 0;
	env = ft_lstnew(envp[i++]);
	while (envp[i] != NULL)
		ft_lstadd_back(&env, ft_lstnew(envp[i++]));
	return (env);
}

int	builtin_env(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		ft_putendl_fd(tmp->var, 1);
		tmp = tmp->next;
	}
	return (0);
}

int	builtin_export(t_list *env, char *name)
{
	t_list	*tmp;

	tmp = env;
	tmp = ft_lstlast(tmp);
	ft_lstadd_back(&tmp, ft_lstnew(name));
	return (0);
}
