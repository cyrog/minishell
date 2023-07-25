/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:49:20 by cgross            #+#    #+#             */
/*   Updated: 2023/07/25 15:49:33 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* opens the file in fdread and put the good value in file_type */
void	r_left(t_token	*new, char *input)
{
	char	*file;

	file = get_filename(new, input);
	new->fdread = open(file, O_RDONLY);
	if (new->fdread == -1)
	{
		perror("issue open r_left");
		new->error = 1;
		g_exit_code = 1;
		return ;
	}
	new->file_type = R_LEFT;
	free(file);
}

/* opens the file in fdread and put the good value in file_type */
void	rr_left(t_token	*new, char *input)
{
	new->i++;
	new->end_of_file = malloc(sizeof(char) * word_len(input, new->i));
	new->end_of_file = get_filename(new, input);
	if (new->fdread == -1)
	{
		perror("issue open rr_left");
		new->error = 1;
		g_exit_code = 1;
		return ;
	}
	new->file_type = R_LEFT;
	heredoc(new, input);
}

/* opens the file in fdwrite and put the good value in file_type */
void	r_right(t_token	*new, char *input)
{
	char	*file;

	file = get_filename(new, input);
	new->fdwrite = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (new->fdread == -1)
	{
		perror("issue open r_right");
		new->error = 1;
		g_exit_code = 1;
		return ;
	}
	new->file_type = R_RIGHT;
	free(file);
}

/* opens the file in fdwrite and put the good value in file_type */
void	rr_right(t_token *new, char *input)
{
	char	*file;

	new->i++;
	file = get_filename(new, input);
	new->fdwrite = open(file, O_CREAT | O_APPEND | O_WRONLY, 0666);
	if (new->fdread == -1)
	{
		perror("issue open rr_right");
		new->error = 1;
		g_exit_code = 1;
		return ;
	}
	new->file_type = RR_RIGHT;
	free(file);
}

/* gets the next word (probably the filename) until | or redirection */
char	*get_filename(t_token *new, char *input)
{
	int		j;
	char	*filename;

	space_index(new, input);
	j = -1;
	if (input[new->i] == '\0')
		return (NULL);
	filename = malloc(sizeof(char) * word_len(input, new->i));
	if (!filename)
		perror("issue malloc get_filename");
	while (input[new->i] && !ft_isaspace(input[new->i]))
	{
		filename[++j] = input[new->i];
		new->i++;
	}
	filename[++j] = '\0';
	return (filename);
}
