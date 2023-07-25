/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:00:31 by cgross            #+#    #+#             */
/*   Updated: 2023/07/25 15:07:16 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/* adds the characters until space or delimiters
and adds it in the token->arg at arg[pos], with a malloc */
void	get_word(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->arg[new->pos] = malloc(sizeof(char) * word_len(input, new->i));
	if (!new->arg[new->pos])
		perror("Issue malloc get_word");
	while (input[new->i] && !isdeli(input[new->i], 's'))
	{
		new->arg[new->pos][++j] = input[new->i];
		new->i++;
	}
	new->arg[new->pos][++j] = '\0';
	space_index(new, input);
}

/* adds what is between the single quotes to the arg at pos */
void	get_squote(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
//	add_tab(new, new->pos);
	new->arg[new->pos] = malloc(sizeof(char) \
	* (strcspn(input, "\'", new->i) + 2));
	if (!new->arg[new->pos])
	{
		perror("Issue malloc get_squote");
		return ;
	}
	while (input[new->i] && input[new->i] != '\'')
	{
		new->arg[new->pos][++j] = input[new->i];
		new->i++;
	}
	new->arg[new->pos][++j] = '\0';
	new->i++;
}

/* adds what is between double quotes to arg and if $env
	adds it to pos + 1 and adds rest of string to pos + 2 */
void	get_dquote(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
	new->arg[new->pos] = malloc(sizeof(char) \
	* (mystrcspn(input, "\"", new->i) + 2));
	if (!new->arg[new->pos])
		perror("Issue malloc get_dquote");
	while (input[new->i] && input[new->i] != '"')
	{
		if (input[new->i] == '$')
			j = env_handler(new, input, j);
		else
		{
			new->flag = 3;
			new->arg[new->pos][++j] = input[new->i];
			new->i++;
		}
	}
	new->arg[new->pos][++j] = '\0';
	new->i++;
}
