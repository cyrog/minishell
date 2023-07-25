/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:52:04 by cgross            #+#    #+#             */
/*   Updated: 2023/07/25 15:46:15 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(char *input, t_env *env)
{
	t_token	*tok;
	int		i;

	tok = NULL;
	i = 0;
	if (closed_quotes(input) == false)
		return (perror("Error with unclosed quotes"));
	while (input[i])
	{
		i = tokenizer(&tok, env, input,  i);
		if (input[i] == '|')
			i++;
	}
	if (!tok->error)
	{
		//replace usd in input;
		//execute;
		print_list(tok);
	}
	free(&tok);
}

/* initializes all the element of the linked list */
void	initok(t_token *new, t_env *envi, int index)
{
	new->cmd = NULL;
	new->arg = NULL;
	new->next = NULL;
	new->flag_env[0] = -1;
	new->error = 0;
	new->flag = 1;
	new->fdread = 1;
	new->fdwrite = 1;
	new->env = envi;
	new->i = index;
	new->arg_all = NULL;
	new->end_of_file = NULL;
	new->g_env = NULL;
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
