/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:34:01 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/07 23:44:03 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_str(char **tmp_str, char *str)
{
	char	*appended_str;

	appended_str = *tmp_str;
	*tmp_str = ft_strjoin(*tmp_str, str);
	free(appended_str);
	return (*tmp_str);
}
