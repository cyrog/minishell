/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:46:08 by cgross            #+#    #+#             */
/*   Updated: 2023/07/25 14:47:00 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* adds what is between the single quotes to the arg at pos */
void	get_squote_cmd(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
	while (input[new->i] && input[new->i] != '\'')
	{
		new->cmd[++j] = input[new->i];
		new->i++;
	}
	new->cmd[++j] = '\0';
	new->i++;
}

/* adds what is between double quotes to arg and if $env
	adds it to pos + 1 and adds rest of string to pos + 2 */
void	get_dquote_cmd(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
	while (input[new->i] && input[new->i] != '"')
	{
			new->cmd[++j] = input[new->i];
			new->i++;
	}
	new->cmd[++j] = '\0';
	new->i++;
}
