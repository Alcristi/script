/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:22:20 by jfrancis          #+#    #+#             */
/*   Updated: 2021/11/11 23:28:54 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordlength(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i = i + 1;
	return (i);
}

static size_t	wordcounter(char const *s, char c)
{
	int	total;
	int	i;

	i = 0;
	total = 0;
	while (s[i] && s[i] == c)
		i = i + 1;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i = i + 1;
		total = total + 1;
		while (s[i] && s[i] == c)
			i = i + 1;
	}
	return (total);
}

static char	*nextword(char const *s, char c)
{
	while (*s && *s == c)
		s = s + 1;
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char	**retstr;
	size_t	i;
	size_t	words;

	if (s != NULL)
	{
		words = wordcounter(s, c);
		retstr = (char **)malloc(sizeof(char *) * (words + 1));
		if (!(retstr))
			return (NULL);
		i = 0;
		while (i < words)
		{
			s = nextword(s, c);
			retstr[i] = ft_substr(s, 0, wordlength(s, c));
			if (!retstr[i])
				return (NULL);
			i = i + 1;
			s += wordlength(s, c);
		}
		retstr[words] = NULL;
		return (retstr);
	}
	return (NULL);
}
