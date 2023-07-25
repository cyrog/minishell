/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:52:04 by cgross            #+#    #+#             */
/*   Updated: 2023/07/25 14:57:18 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(char *input)
{
	t_token	*tok;
	int		i;

	tok = NULL;
	i = 0;
	if (closed_quotes(input) == false)
		return (perror("Error with unclosed quotes"));
	while (input[i])
	{
		i = tokenizer(&tok, input, i);
		if (input[i] == '|')
			i++;
	}
}

void	initok(t_token *tok, int index)
{
	tok->cmd = NULL;
	tok->arg = NULL;
	tok->i = index;
	tok->pos = 0;
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
