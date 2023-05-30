/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/05/30 16:59:31 by cgross           ###   ########.fr       */
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

int	main(int ac, char **av, char **envp)
{
	char	*input;

	(void)ac;
	(void)av;
	input = "start";
	while (input)
	{
		input = readline("minishell >> ");
		exec_cmd(envp, input); //testing
		//printf("%s\n", input);
	}
	return (0);
}
