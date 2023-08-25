/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:31:28 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/25 14:16:31 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_quotes(char *input)
{
	bool	closed;
	int		scount;
	int		dcount;
	int		i;

	closed = false;
	i = 0;
	scount = 0;
	dcount = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			scount++;
		if (input[i] == '\"')
			dcount++;
		i++;
	}
	if (scount % 2 == 0 && dcount % 2 == 0)
		closed = true;
	return (closed);
}

void	parser(char	*input, t_env *envi)
{
	t_token	*head;
	int		i;

	i = 0;
	head = NULL;
	if (!check_quotes(input))
	{
		perror("Issue with the quotes");
		return ;
	}
	while (input[i])
	{
		i = sequencer(&head, input, envi, i);
		if (input[i] == '|')
			i++;
	}
	if (!head->error)
	{
//		replace_usd(head);
//		execution(head);
		print_list(head);
	}
	free_token(&head);
}

void	initialize_sequence(t_token *new, t_env *envi, int index)
{
	new->cmd = NULL;
	new->arg = NULL;
	new->next = NULL;
	new->flag_env[0] = -1;
	new->error = 0;
	new->flag = 1;
	new->fdread = 1;
	new->fdwrite = 1;
	(void)envi;
	//new->env = envi;
	new->i = index;
	new->arg_all = NULL;
	new->end_of_file = NULL;
	new->g_env = NULL;
}
