/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:55:14 by cgross            #+#    #+#             */
/*   Updated: 2023/05/25 17:46:55 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//cutting input into words

int	tokenizer(t_tok *head, char *input, int index)
{
	t_tok *new;

	new = malloc(sizeof(t_tok));
	tok_init(new, index);
	if (input == NULL || input[new->i] == '\0')
	{
		perror("empty input");
		return (-1);
	}
	spaceindex(new, input);
	while (input[new->i] && input[new->i] != '|')
	{

}

int	main(void)
{
	t_tok	*token = malloc(sizeof(t_tok));
	int		index = 0;
	char	input[] = "ls -la";

	tokenizer(token, input, index);

