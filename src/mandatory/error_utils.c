/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 02:15:00 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/11 03:39:42 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/pipex.h"

void	print_error(int id_error)
{
	char	*error_msg;

	error_msg = 0;
	if (id_error == 1)
		error_msg = "Too few arguments";
	else if (id_error == 2)
		error_msg = "Too many arguments";
	else if (id_error == 3)
		error_msg = "Error while creating pipe";
	else if (id_error == 4)
		error_msg = "Error while opening file";
	else if (id_error == 4)
		error_msg = "Error while forking around";
	else if (id_error == 5)
		error_msg = "Error: command not found";
	ft_putstr_fd(error_msg, 2);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
