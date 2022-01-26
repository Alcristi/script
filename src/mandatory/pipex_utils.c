/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:28:44 by coder             #+#    #+#             */
/*   Updated: 2021/11/11 22:57:59 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	init_pipeline(int argc, char **argv, t_pipe *pipeline)
{
	if (argc < 5)
		print_error(1);
	if (argc > 5)
		print_error(2);
	pipeline->infile = open(argv[1], O_RDONLY);
	if (pipeline->infile < 0)
		print_error(4);
	pipeline->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipeline->outfile < 0)
		print_error(4);
	if (pipe(pipeline->fd) < 0)
		print_error(3);
}

void	pipex_fork(char **argv, char **envp, t_pipe *pipeline)
{
	pipeline->pid_fc = fork();
	if (pipeline->pid_fc == 0)
		first_child_process(argv, envp, pipeline);
	pipeline->pid_sc = fork();
	if (pipeline->pid_sc == 0)
		second_child_process(argv, envp, pipeline);
}

void	close_pipes(t_pipe *pipeline)
{
	close(pipeline->fd[0]);
	close(pipeline->fd[1]);
}
