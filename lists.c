/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:57:05 by cgross            #+#    #+#             */
/*   Updated: 2023/05/25 15:03:05 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_last(t_tok **head, t_tok *new)
{
	t_tok	*tmp;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	tmp = get_last(*head);
	tmp->next = new;
}

t_tok	*get_last(t_tok *head)
{
	t_tok	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
