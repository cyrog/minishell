/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:52:04 by cgross            #+#    #+#             */
/*   Updated: 2023/07/21 14:55:37 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(char *input)
{
	if (closed_quotes(input) == false)
		return (perror("Error with unclosed quotes"));
}

void	initok(t_token *tok)
{
	tok->cmd = NULL;
	tok->arg = NULL;
	tok->next = NULL;
}

/*int	main()
{
	t_token *tok;

	tok = malloc(sizeof(t_token));
	tok->input = "'ls -la'' | grep 2'";
	//printf("closed : %d", closed_quotes(tok->input));
	parser(tok->input);
	
}
*/