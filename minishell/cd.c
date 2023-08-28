/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:46:51 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/28 18:04:26 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_var(t_env *env, char *name)
{
	t_env	*curr = env;

	while (curr)
	{
		if (strcmp(curr->name, name) == 0)
		{
			return (curr->value);
		}
		if (!curr->next) 
		{
			return (NULL);
		}
		curr = curr->next;
	}
	return (NULL);
}

void	ft_cd(t_token *tok)
{
	char *cwd;

	cwd = malloc(PATH_MAX);
	getcwd(cwd, PATH_MAX);
	if ((ft_strcmp(tok->arg[0], "~") == 0) || (ft_strcmp(tok->arg[0], "") == 0))
	{
		if (chdir(find_var(tok->env, "HOME")) != 0)
		{
			perror("$HOME error");
			return;
		}
	}
	else if (ft_strcmp(tok->arg[0], "-") == 0)
	{
		if (chdir(find_var(tok->env, "OLDPWD")) != 0)
		{
			perror("$OLDPWD error");
			return;
		}
	}
    else if (chdir(tok->arg[0]) != 0)
	{
		perror("chdir error");
		return;
	}
	ft_export(tok->env, "OLDPWD", cwd);
	free(cwd);
	cwd = malloc(PATH_MAX);
	getcwd(cwd, PATH_MAX);
	ft_export(tok->env, "PWD", cwd);
	free(cwd);
}
