/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:24:04 by cgross            #+#    #+#             */
/*   Updated: 2023/08/28 16:45:32 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isbuiltin(t_token *token)
{
	if (ft_strcmp(token->cmd, "echo") == 0
			|| ft_strcmp(token->cmd, "cd") == 0
			|| ft_strcmp(token->cmd, "exit") == 0
			|| ft_strcmp(token->cmd, "export") == 0
			|| ft_strcmp(token->cmd, "unset") == 0
			|| ft_strcmp(token->cmd, "env") == 0
			|| ft_strcmp(token->cmd, "pwd") == 0)
		return (0);
	else
		return (1);
}
