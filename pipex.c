/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:30:37 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/08 18:00:00 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// first dup2 : content of file1 accessible via STDIN
// second dup2 : cmd1 will write in pipe instead on STDOUT

static void	first_child(char **argv, int *fd, char **envp)
{
	int	file1;

	close(fd[0]);
	file1 = open(argv[1], O_RDONLY, 0777);
	if (file1 == -1)
		ft_error();
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(file1);
	ft_execute(argv[2], envp);
}

// first dup2 : cmd2 will write in file2 instead of STDOUT
// second dup2 : cmd2 will read in pipe instead on STDIN
static void	second_child(char **argv, int *fd, char **envp)
{
	int	file2;

	close(fd[1]);
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file2 == -1)
		ft_error();
	dup2(file2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(file2);
	ft_execute(argv[3], envp);
}

// pipe between cmd1 et cmd2
int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		pid1 = fork();
		if (pid1 == 0)
			first_child(argv, fd, envp);
		pid2 = fork();
		if (pid1 == -1 || pid2 == -1)
			ft_error();
		if (pid2 == 0)
			second_child(argv, fd, envp);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		ft_putstr_fd("You must have 4 arguments\n", STDERR_FILENO);
	return (0);
}

/*
int	ft_exec(void)
{
	pid_t	pid;

	pid = fork()
	if (!pid)
	{
		do_child;
	}
	else
	{
		close_pipes
	}
}


int	main(void)
{
	int	fd[2];

	while (i < amount_cmds)
	{
		ft_exec(cmd[i])
		i++;
	}
	while (i < num_of_childs)
	{
		waitpid(NULL);
	}
}
*/