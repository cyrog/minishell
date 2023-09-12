/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:13:59 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/12 15:12:33 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

/*
	t_env *temp;

	temp = *env;
	if (temp->next == NULL)
	{
		*env = NULL;
		return;
	}
	*env = (*env)->next;
	(*env)->previous = NULL;
	free(temp->name);
	free(temp->value);
	free(temp);
}
*/
void	debug(t_env **env)
{
	t_env *tmp;

	tmp = *env;
	while(tmp)
	{
		printf("name: [%s], value: [%s]\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
	printf("END ENV ---------- \n");
}


void	ft_unset(t_env **env, char *name)
{
	t_env	*curr;

	curr = *env;
	if (curr == NULL)
		return ;
	debug(env);
	while (*env)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			if (curr->previous == NULL)
			{
				*env = curr->next;
				if ((*env) != NULL)
					(*env)->previous = NULL;
				else
				{
					curr->previous->next = curr->next;
					if (curr->next != NULL)
						curr->next->previous = curr->previous;
				}
				free(curr->name);
				free(curr->value);
				free(curr);
				curr = NULL;
				debug(env);
				printf("ok////////////////////\n");
				return ;
			}
			else if (!curr->next)
				curr->previous->next = NULL;
			else
			{
				curr->previous->next = curr->next;
				curr->next->previous = curr->previous;
			}
			free(curr->value);
			curr->value = NULL;
			free(curr->name);
			curr->name = NULL;
			free(curr);
			curr = NULL;
			debug(env);
			return ;
		}
		*env = (*env)->next;
	}
}

int	ft_unset_parse(t_token *s, t_env *env)
{
	char	*str;

	str = ft_dechar(s->arg);
	if (ft_strchr(str, '='))
	{
		ft_putstr_fd("minishell: unset: ", 2);
		ft_putstr_fd("'", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		free(str);
		return (1);
	}
	ft_unset(&env, str);
	free(str);
	return (0);
}
