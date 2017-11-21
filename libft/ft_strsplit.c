/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:12:57 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/16 02:19:33 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_words(char const *s, char c)
{
	size_t	res;
	size_t	i;

	i = 0;
	res = 0;
	if (*s != c && *s)
		res++;
	if (s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			res++;
		i++;
	}
	return (res);
}

static char		*new_word(char const *s, char c)
{
	size_t	n;
	char	*word;

	n = 0;
	while (s[n] != c && s[n])
		n++;
	word = ft_strsub(s, 0, n);
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**new;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	new = (char **)malloc((nb_words(s, c) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	if (s[i] != c && s[i])
		new[j++] = new_word(s, c);
	if (s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			new[j++] = new_word(&s[i], c);
		i++;
	}
	new[j] = NULL;
	return (new);
}
