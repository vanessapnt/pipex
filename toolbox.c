/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:32:10 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/08 18:05:34 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

//arg = "ls"
//F_OK tests for the existence of the file.
void	ft_free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_begin;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_begin = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_begin, cmd);
		free(path_begin);
		if (access(path, F_OK) == 0)
		{
			ft_free_double(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_double(paths);
	return (NULL);
}

//split puts an \0 at the end of cmd
//*path = "/bin/ls"
//**cmd = {ls, "-l", NULL}
//ENOENT 2 No such file or directory
void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		ft_free_double(cmd);
		errno = ENOENT;
		ft_error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_free_double(cmd);
		ft_error();
	}
}
