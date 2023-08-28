/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/28 18:02:49 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_token *token)
{
	int	pid = 0;
	int status = 0;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (isbuiltin(token) == 0)
			exec_builtin(token);
//		if (execve(get_right_path(*cmd), cmd, envp) == -1)
//			perror("shell");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_token	*tok;
	t_env	*env;
	char	*input;
	//char *args[] = {"ls", "-la", NULL};

	tok = (t_token *)malloc(sizeof(t_token));
	if (!tok)
		return (-1);
	//env = malloc(sizeof(t_env));
	//memset(env, 0, sizeof(t_env));
	(void)argv;
	(void)argc;
//	input = "start";
	env = init_env(envp);
	signalsinit();
	//ft_env(env);
	//ft_export(env, "TEST", "42");
	//ft_unset(&env, "TERM_SESSION_ID");
	//exec_cmd(args, envp);
	//ft_exit(env);
	//ft_cd(env, "~");
	//ft_pwd();
	//ft_echo("test salut", 0);
	while (42)
	{
		//if ((input = readline("minishell >> ")) == NULL)
		//	ft_exit(env); // ctrl+d = exit
		input = readline("minishell >> ");
		if (input == NULL || input[0] == '\0')
			continue;
		parser(input, env);
		add_history(input);
		free(input);
	}
	free(input);
	clear_history();
	//free env
	return (0);
}
