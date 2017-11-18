/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:36:50 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/17 19:35:02 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	word_count(char const *s, char c)
{
	int a;
	int b;
	int i;

	i = 0;
	b = 0;
	a = 1;
	while (s[i])
	{
		if (s[i] != c && a)
		{
			a = 0;
			b++;
		}
		if (s[i] == c)
			a = 1;
		i++;
	}
	return (b);
}

static void	alloc_tabs(char const *s, char c, char **tab)
{
	int a;
	int b;
	int i;

	i = 0;
	b = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != c)
			b++;
		if ((s[i] == c && b) || (s[i] != c && !s[i + 1]))
		{
			tab[a] = (char *)malloc(b + 1);
			a++;
			b = 0;
		}
		i++;
	}
	tab[a] = malloc(1);
}

static void	fill_tabs(char const *s, char c, char **tab)
{
	int a;
	int b;
	int i;

	b = 0;
	a = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[a][b] = s[i];
			b++;
		}
		if ((s[i] == c && b) || (s[i] != c && !s[i + 1]))
		{
			tab[a][b] = '\0';
			a++;
			b = 0;
		}
		i++;
	}
	tab[a] = 0;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		a;

	if (!s)
		return (NULL);
	a = word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * a + 1);
	if (!tab)
		return (NULL);
	alloc_tabs(s, c, tab);
	fill_tabs(s, c, tab);
	return (tab);
}
