/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:34:29 by cgross            #+#    #+#             */
/*   Updated: 2023/05/25 15:21:39 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_H
# define GRAMMAR_H

typedef struct	s_env
{
	char	**env;
	char	*path;

}			t_env;

typedef struct	s_tok
{
	t_env	*env;

	int		pos;
	int		i;

	char	*cmd;
	char	**arg;

	struct s_token	*next;
}			t_tok;

#endif
