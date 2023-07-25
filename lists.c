/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:25:28 by cgross            #+#    #+#             */
/*   Updated: 2023/07/25 14:25:04 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//return last element of the list;
t_token	*get_last(t_token *list)
{
	t_token	*tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

//add element at the end of the list;
void	add_last(t_token **list, t_token *new)
{
	t_token	*tmp;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	tmp = get_last(*list);
	tmp->next = new;
}

//print the list content(cmd + arg);
void	print_list(t_token *list)
{
	t_token	*tmp;
	int		i;

	tmp = list;
	while (tmp)
	{
		i = 0;
		printf("cmd: [%s]", tmp->cmd);
		while (tmp->arg[i])
			printf("arg: [%s]", tmp->arg[i++]);
		printf("\n");
		tmp = tmp->next;
	}
}
