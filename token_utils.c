/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:29:00 by cgross            #+#    #+#             */
/*   Updated: 2023/05/25 16:31:54 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		isaspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

void	spaceindex(t_tok *new, char *input)
{
	while (input[new->i] && isaspace(input[new->i]))
		new->i++;
}
