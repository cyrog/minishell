/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:47:56 by cgross            #+#    #+#             */
/*   Updated: 2023/08/28 17:11:05 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_token *token)
{
	if (ft_strcmp(token->cmd, "pwd") == 0)	// works !
		ft_pwd();
	else if (ft_strcmp(token->cmd, "exit") == 0) // :(
		ft_exit(token);
	else if (ft_strcmp(token->cmd, "env") == 0) // :(
		ft_env(token->env);
	else if (ft_strcmp(token->cmd, "cd") == 0)
		ft_cd(token);
}

