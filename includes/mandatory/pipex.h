/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:12:10 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/11 22:55:17 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include "../../libs/libft/libft.h"

typedef struct s_pipe {
	int		infile;
	int		outfile;
	int		fd[2];
	char	**p_argvs;
	char	**p_cmds;
	char	*paths;
	char	*cmd;
	pid_t	pid_fc;
	pid_t	pid_sc;
}						t_pipe;

void	print_error(int id_error);
void	init_pipeline(int argc, char **argv, t_pipe *pipeline);
char	*get_path_var(char **envp);
void	close_pipes(t_pipe *pipeline);
void	pipex_fork(char **argv, char **envp, t_pipe *pipeline);
void	first_child_process(char **argv, char **envp, t_pipe *pipeline);
void	second_child_process(char **argv, char **envp, t_pipe *pipeline);
char	*get_cmd(char **paths, char *cmd);
void	destroy_child(t_pipe *pipeline);
void	destroy_parent(t_pipe *pipeline);

#endif