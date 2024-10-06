/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:30:37 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/06 17:13:39 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// first dup2 : content of file1 accessible via STDIN
// second dup2 : cmd1 will write in pipe instead on STDOUT

static void	child_process(char **argv, int *fd)
{
	int	file1;

	close(fd[0]);
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		ft_error();
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	ft_execute(argv[2]);
	close(fd[1]);
}

// first dup2 : cmd2 will write in file2 instead of STDOUT
// second dup2 : cmd2 will read in pipe instead on STDIN
static void	parent_process(char **argv, int *fd)
{
	int	file2;

	close(fd[1]);
	file2 = open(argv[4], O_RDONLY);
	if (file2 == -1)
		ft_error();
	dup2(file2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	ft_execute(argv[3]);
	close(fd[0]);
}

// pipe between cmd1 et cmd2
int	main(int argc, char **argv)
{
	int fd[2];
	int pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		pid = fork();
		if (pid == -1)
			ft_error();
		if (pid == 0)
			child_process(argv, fd);
		wait(NULL);
		parent_process(argv, fd);
	}
	else
		ft_putstr_fd("You must have 4 arguments\n", STDERR_FILENO);
	return (0);
}