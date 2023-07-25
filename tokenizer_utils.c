/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:45:28 by cgross            #+#    #+#             */
/*   Updated: 2023/07/25 15:20:53 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redi(char c)
{
	if (c == '<' || c == '>')
		return (true);
	return (false);
}

bool	is_aspace(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

/* returns true if char is a delimiter
	if flag == s takes into account the spaces */
bool	isdeli(char c, char flag)
{
	if (c == '|' || c == '<' || c == '>')
		return (true);
	if (flag == 's' && is_aspace(c))
		return (true);
	return (false);
}

//iterates the index after removing the spaces
void	space_index(t_token *new, char *input)
{
	while (input[new->i] && is_aspace(input[new->i] == true))
		new->i++;
}
