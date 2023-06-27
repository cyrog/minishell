/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/06/27 13:06:52 by cgross           ###   ########.fr       */
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
	t_arg *arg;
	int i = 0;

	(void)ac;
	(void)av;
	arg = malloc(sizeof(t_arg));
	arg->input = NULL;
	while (1)
	{
		arg->input = readline("minishell >> ");
		exec_cmd(envp, arg->input); //testing
		printf("input: [%s]\n", arg->input);
		while (arg->args[i++])
		{
			arg->args = get_args(arg);
			printf("arg[i] : %s[%i]", arg->args[i], i);
		}
		printf("input: [%s]\n", arg->input);
	}
	return (0);
}
