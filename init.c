/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:46:48 by cgross            #+#    #+#             */
/*   Updated: 2023/05/25 15:22:49 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tok_init(t_tok *new, int index)
{
	new->cmd = NULL;
	new->arg = NULL;
	new->next = NULL;
	new->i = index;
}
