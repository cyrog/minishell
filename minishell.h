/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:19 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/21 14:46:30 by cgross           ###   ########.fr       */
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
# include <stdbool.h>

/*typedef struct	s_arg
{
	char			*input;
	char			**pipsplit;
	char			**args;
	char			*path;
	struct s_arg	*next;
}				t_arg;
*/

typedef struct	t_token
{
	char	*input;
	char	*cmd;
	char	*arg;
	struct s_token	*next;
}	t_token;

void	exec_cmd(char **envp, char *cmd);
void	ft_free(char **str);

char	**ft_split(char const *s, char c);

char	*get_right_path(char *cmd);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(const char *str);
char	*ft_strtrim(const char *s1, const char *set);

int		isaspace(char c);

//parsing
bool	closed_quotes(char *input);
void	parser(char *input);
void	initok(t_token *tok);

#endif 
