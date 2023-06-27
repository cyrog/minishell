/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:19 by lobertho          #+#    #+#             */
/*   Updated: 2023/06/27 14:04:57 by cgross           ###   ########.fr       */
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

typedef struct	s_arg
{
	char			*input;
	char			**pipsplit;
	char			**args;
	char			*path;
	struct s_arg	*next;
}				t_arg;

void	exec_cmd(char **envp, char *cmd);
void	ft_free(char **str);

char	**ft_split(char const *s, char c);

char	*get_right_path(char *cmd);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(const char *str);
char	*ft_strtrim(const char *s1, const char *set);

int		isaspace(char c);

t_arg 	*arg_init(t_arg *arg);

char	**pip_split(t_arg *arg);

#endif 
