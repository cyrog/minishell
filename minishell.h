/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:19 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/25 15:02:11 by cgross           ###   ########.fr       */
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

typedef struct	s_token
{

	int		type;
	int		i;
	int		pos;
	char	*input;
	char	*cmd;
	char	**arg;
	struct s_token	*next;
}	t_token;

enum e_token
{
	COMMAND = 1,
	ARG = 2,
};

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*previous;
	struct s_env	*next;
}	t_env;

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
void	initok(t_token *tok, int index);

//chained lists
t_token *get_last(t_token *list);
void	add_last(t_token **list, t_token *new);
void	print_list(t_token *list);

//tokenizer
int		tokenizer(t_token **tok, char *input, int index);
void	get_cmd(t_token *new, char *input);
void	get_arg(t_token *new, char *input);
int		word_len(char *input, int i);

//tokenizer utils
bool	is_redi(char c);
bool	is_aspace(char c);
bool	isdeli(char c, char flag);
void	space_index(t_token *new, char *input);

//get
void	get_word(t_token *new, char *input);
void	get_squote(t_token *new, char *input);
void	get_dquote(t_token *new, char *input);

//get_quote
void	get_squote_cmd(t_token *new, char *input);
void	get_dquote_cmd(t_token *new, char *input);


#endif 
