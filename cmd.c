/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:05:18 by cgross            #+#    #+#             */
/*   Updated: 2023/05/23 16:57:17 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_cmd(t_parse *parse, char *raw_cmd)
{
	parse->cmd = ft_split(raw_cmd, ' ');	
	return (parse->cmd);
}
