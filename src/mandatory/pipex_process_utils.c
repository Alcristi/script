/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:20:25 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/11 04:03:04 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	destroy_parent(t_pipe *pipeline)
{
	int	i;

	i = 0;
	close(pipeline->infile);
	close(pipeline->outfile);
	while (pipeline->p_cmds[i])
	{
		free(pipeline->p_cmds[i]);
		i++;
	}
	free(pipeline->p_cmds);
}

void	destroy_child(t_pipe *pipeline)
{
	int	i;

	i = 0;
	while (pipeline->p_argvs[i])
	{
		free(pipeline->p_argvs[i]);
		i++;
	}
	free(pipeline->p_argvs);
	free(pipeline->cmd);
}
