/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:33:21 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/11 22:22:11 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	first_child_process(char **argv, char **envp, t_pipe *pipeline)
{
	dup2(pipeline->fd[1], 1);
	close(pipeline->fd[0]);
	dup2(pipeline->infile, 0);
	pipeline->p_argvs = ft_split(argv[2], ' ');
	pipeline->cmd = get_cmd(pipeline->p_cmds, pipeline->p_argvs[0]);
	if (!pipeline->cmd)
	{
		destroy_child(pipeline);
		print_error(5);
	}
	execve(pipeline->cmd, pipeline->p_argvs, envp);
}

void	second_child_process(char **argv, char **envp, t_pipe *pipeline)
{
	dup2(pipeline->fd[0], 0);
	close(pipeline->fd[1]);
	dup2(pipeline->outfile, 1);
	pipeline->p_argvs = ft_split(argv[3], ' ');
	pipeline->cmd = get_cmd(pipeline->p_cmds, pipeline->p_argvs[0]);
	if (!pipeline->cmd)
	{
		destroy_child(pipeline);
		print_error(5);
	}
	execve(pipeline->cmd, pipeline->p_argvs, envp);
}
