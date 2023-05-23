/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/05/23 17:56:55 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(char **envp, char *cmd)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = 0;
	//on fork pour creer un processus enfant
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		//on fait attendre le processus parent jusqua ce que l enfant termine
		waitpid(pid, &status, 0);
		//on termine le processus enfant
		kill(pid, SIGTERM);
	}
	else
	{
		//le processus enfant execute la commande ou exit si ca echoue
		if (execve(get_right_path(cmd), &cmd, envp) == -1)
			perror("minishell");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	t_data *data;
	char	*input;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	input = "start";
	while (input)
	{
		input = readline("minishell >> ");
		//add_history(s->line);
		//ft_lexer(s);
		//exec_cmd(envp, "ls");
		//ft_free(s->lexer);
		printf("%s\n", input);
	}

	//some nice segfaults
	/*data->parse->cmd = ft_split(input, ' ');
	data->env->path = get_right_path(data->parse->cmd[0]);
	printf("[%s]\n", data->env->path);
	printf("[%s]\n", data->parse->cmd);
	*/
	return (0);
}
