/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:39:25 by jnavalla          #+#    #+#             */
/*   Updated: 2025/06/03 18:14:56 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>

//////////////pipex.c//////////////
char	*get_command_path(char *cmd, char **envp);
void	first_command_exec(char **envp, int *pipefd, int infile, char **argv);
void	second_command_exec(char **envp, int *pipefd, int outfile, char **argv);
int		init_fds_pipe(int *infile, int *outfile, int pipefd[2], char **argv);
//////////////utils.c//////////////
char	*join_path(char *dir, char *cmd);
void	free_args(char **args);
void	print_cmd_error(char *cmd);
#endif