/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:19 by lobertho          #+#    #+#             */
/*   Updated: 2023/05/23 17:28:58 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>

typedef struct	s_env
{
	char	**env_path;
	char	*path;
}			t_env;

typedef struct	s_parse
{
	char	**cmd;
}			t_parse;

typedef struct	s_data
{
	t_env	*env;
	t_parse	*parse;
}				t_data;


int		init(t_data *data);
void	ft_lexer(t_data *s);
void	exec_cmd(char **envp, char *cmd);
void	ft_free(char **str);

char	**ft_split(char const *s, char c);

char	*get_right_path(char *cmd);

char	*ft_strjoin(char const *s1, char const *s2);

#endif 
