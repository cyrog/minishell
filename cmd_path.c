/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:11:28 by cgross            #+#    #+#             */
/*   Updated: 2023/05/25 15:28:00 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_all_path() //getenv path and splits it
{
	char **all_paths;
   
	all_paths = ft_split(getenv("PATH"), ':');
	if (all_paths == NULL)
	{
		ft_free(all_paths);
		return (NULL);
	}
	else
		return (all_paths);
}

char *get_right_path(char *cmd) //finds right path for cmd
{
	int     i;
	char    *temp;
	char	**all_paths;
	char    *path;

	i = -1;
	all_paths = get_all_path();
	while (all_paths && all_paths[++i])
	{
		temp = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		if (access(path, X_OK) != -1)
		{
			free(temp);
			ft_free(all_paths);
			return (path);
		}
		free(path);
		free(temp);
	}
	ft_free(all_paths);
	return (NULL);
}

/*int	main(void)
{
	get_right_path("ls");
}
*/


// get_env->all_path function return value
 
/*int main(void)
{
	char **split_path = get_all_path();
	int	i = 0;
	while (split_path[i])
	{
		printf("path[i]	[%d] [%s]\n", i, split_path[i]);
		i++;
	}
}
*/
