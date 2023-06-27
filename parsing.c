/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:52:04 by cgross            #+#    #+#             */
/*   Updated: 2023/06/27 15:55:34 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**pip_split(t_arg *arg)
{
	char	*copy;
	int		i;
	
	i = 0;
	copy = ft_strcpy(arg->input);
	arg->pipsplit = ft_split(copy, '|');
	//printf("pip_split[i] = %s[%d]\n", arg->pipsplit[i], i);
	while (arg->pipsplit[i])
	{
		arg->pipsplit[i] = ft_strtrim(arg->pipsplit[i], " ");
		i++;
	}
	return (arg->pipsplit);
}

int	main()
{
	t_arg *arg;
	arg = malloc(sizeof(t_arg));
	arg->input = "'ls -la | echo ' letsgo";
	int		i = 0;
	arg->pipsplit = pip_split(arg);

	//printf("arg->input = %s", arg->input);
	//printf("pip_split[i] = %s[%d]\n", arg->pipsplit[i], i);
	while (arg->pipsplit[i])
		printf("main loop: [%s]\n", arg->pipsplit[i++]);
}
