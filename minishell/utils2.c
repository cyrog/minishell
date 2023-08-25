/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:02:24 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/25 14:22:11 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_splitname(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] != '=')
		i++;
	name = malloc(sizeof(char) * i + 1);
	i = 0;
	while(str[i] != '=')
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

char *ft_splitvalue(char *str)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	while (str[i] != '=')
		i++;
	i++;
	j = i;
	while (str[i])
		i++;
	i = i - j;
	value = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[j] != '\0')
		value[i++] = str[j++];
	value[i] = '\0';
	return (value);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write (fd, &s[i++], 1);
}

void	add_tab(t_token *token, int new)
{
	int	i;

	i = 0;
	while (token->flag_env[i] != -1)
		i++;
	token->flag_env[i] = new;
	token->flag_env[i + 1] = -1;
}
