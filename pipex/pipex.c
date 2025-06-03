/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:27:07 by jnavalla          #+#    #+#             */
/*   Updated: 2025/06/03 18:14:47 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;

	if (!cmd || !envp)
		return (NULL);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
			return (free_args(paths), full_path);
		free(full_path);
		i++;
	}
	free_args(paths);
	return (NULL);
}

void	first_command_exec(char **envp, int *pipefd, int infile, char **argv)
{
	char	**args1;
	char	*path1;

	args1 = ft_split(argv[2], ' ');
	path1 = get_command_path(args1[0], envp);
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	if (!path1)
	{
		print_cmd_error(args1[0]);
		free_args(args1);
		exit(127);
	}
	execve(path1, args1, envp);
	perror("execve (cmd1)");
	exit(EXIT_FAILURE);
}

void	second_command_exec(char **envp, int *pipefd, int outfile, char **argv)
{
	char	**args2;
	char	*path2;

	args2 = ft_split(argv[3], ' ');
	path2 = get_command_path(args2[0], envp);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	if (!path2)
	{
		print_cmd_error(args2[0]);
		free_args(args2);
		exit(127);
	}
	execve(path2, args2, envp);
	perror("execve (cmd2)");
	exit(EXIT_FAILURE);
}

int	init_fds_pipe(int *infile, int *outfile, int pipefd[2], char **argv)
{
	*infile = open(argv[1], O_RDONLY);
	if (*infile < 0)
		return (perror(argv[1]), 1);
	*outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*outfile < 0)
	{
		close(*infile);
		return (perror(argv[4]), 1);
	}
	if (pipe(pipefd) == -1)
	{
		close(*infile);
		close(*outfile);
		return (perror("pipe"), 1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
		return (1);
	}
	if (init_fds_pipe(&infile, &outfile, pipefd, argv))
		return (1);
	pid1 = fork();
	if (pid1 == 0)
		first_command_exec(envp, pipefd, infile, argv);
	pid2 = fork();
	if (pid2 == 0)
		second_command_exec(envp, pipefd, outfile, argv);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
