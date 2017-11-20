/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 04:30:17 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/20 09:22:23 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** CHECK_TERTRIMINOS
** lance tous les tests sur le buf et retourne 1 si tout est valide
*/

static int	test_nb_lines(char *buf)
{
	int i;

	i = 0;
	while (buf[i++])
		if ((i + 1) % 5 == 0 && buf[i] != '\n')
			return (0);
	return (1);
}

static int	sidehash(char **tab, int i, int j)
{
	if (i > 0 && tab[i - 1][j] == '#')
		return (1);
	else if (i < 3 && tab[i + 1][j] == '#')
		return (1);
	else if (j > 0 && tab[i][j - 1] == '#')
		return (1);
	else if (j < 3 && tab[i][j + 1] == '#')
		return (1);
	return (0);
}

static int	test_chars(char *buf)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = ft_strsplit(buf, '\n');
	if (ft_charoc(buf, '#') != 4)
		return (0);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '.' && tab[i][j] != '#')
				return (0);
			if (tab[i][j] == '#' && !sidehash(tab, i, j))
				return (0);
			j++;
		}
		i++;
	}
	cleanup(tab);
	return (1);
}

int			check_tetriminos(char *av)
{
	int		fd;
	char	buf[22];
	int		ret;
	int		nb_tetriminos;

	nb_tetriminos = 0;
	fd = open(av, O_RDONLY);
	if (fd == 1)
		return (0);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (!test_nb_lines(buf))
			return (0);
		if (!test_chars(buf))
			return (0);
		nb_tetriminos++;
	}
	return (nb_tetriminos);
}
