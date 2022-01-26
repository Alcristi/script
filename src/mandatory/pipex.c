/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:14:57 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/11 22:58:55 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipeline;

	init_pipeline(argc, argv, &pipeline);
	pipeline.paths = get_path_var(envp);
	pipeline.p_cmds = ft_split(pipeline.paths, ':');
	pipex_fork(argv, envp, &pipeline);
	close_pipes(&pipeline);
	waitpid(pipeline.pid_fc, NULL, 0);
	waitpid(pipeline.pid_sc, NULL, 0);
	destroy_parent(&pipeline);
	return (0);
}
