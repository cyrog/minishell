/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:39:58 by cgross            #+#    #+#             */
/*   Updated: 2023/07/25 14:53:41 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokenizer(t_token **tok, char *input, int index)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (-1);
	initok(new, index);
	space_index(new, input);
	while (input[new->i] && input[new->i] != '|')
	{
		if (is_redi(input[new->i]))
			//get_redi function
		get_cmd(new, input);
		//get_arg
	}
	add_last(tok, new);
	return (new->i);
}

void	get_cmd(t_token *new, char *input)
{
	int		j;

	j = -1;
	new->cmd = malloc(sizeof(char) * word_len(input, new->i));
	if (!new->cmd)
		perror("Issue malloc get_cmd");
	if (input[new->i] == '\'')
		get_squote_cmd(new, input);
	else if (input[new->i] == '"')
		get_dquote_cmd(new, input);
	else
	{
		while (input[new->i] && !is_aspace(input[new->i]) && input[new->i] != '|')
		{
			new->cmd[++j] = input[new->i];
			new->i++;
		}
		new->cmd[++j] = '\0';
	}
	new->type = COMMAND;
	new->next = NULL;
	space_index(new, input);
}

/* returns the length of the next word to be malloc*/
int	word_len(char *input, int i)
{
	int	len;

	len = 0;
	while (input[i] && !isdeli(input[i], '!'))
	{
		len++;
		i++;
	}
	return (len + 1);
}
