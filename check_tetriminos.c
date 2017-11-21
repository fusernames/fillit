/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 04:30:17 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/21 07:30:48 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** CHECK_TERTRIMINOS
** lance tous les tests sur le buf et return nb tetriminos si tout est valide
*/

static int	test_nb_lines(char *buf)
{
	int i;
	int count_line;
	int count_point;
	int count_hash;

	count_line = 0;
	count_point = 0;
	count_hash = 0;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '\n')
			count_line++;
		if (buf[i] == '.')
			count_point++;
		if (buf[i] == '#')
			count_hash++;
		i++;
	}
	if (count_line != 4 || count_hash != 4 || count_point != 12)
		return (0);
	if (buf[20] == '\n')
		count_line++;
	return (count_line);
}

static int	sidehash(char **tab, int i, int j)
{
	int count_sidehash;

	count_sidehash = 0;
	if (i + 1 < 4 && tab[i + 1][j] == '#')
		count_sidehash++;
	if (i - 1 > -1 && tab[i - 1][j] == '#')
		count_sidehash++;
	if (j + 1 < 5 && tab[i][j + 1] == '#')
		count_sidehash++;
	if (j - 1 > -1 && tab[i][j - 1] == '#')
		count_sidehash++;
	return (count_sidehash);
}

static int	test_chars(char *buf)
{
	char	**tab;
	int		i;
	int		j;
	int		count_sidehash;

	i = 0;
	count_sidehash = 0;
	tab = ft_strsplit(buf, '\n');
	if (ft_charoc(buf, '#') != 4)
		return (0);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				count_sidehash += sidehash(tab, i, j);
			j++;
		}
		i++;
	}
	if (count_sidehash < 6)
		return (0);
	cleanup(tab);
	return (1);
}

int			check_tetriminos(char *av)
{
	int		fd;
	char	buf[22];
	int		ret;
	int		nb_tetriminos;
	int		backslach_n;

	nb_tetriminos = 0;
	backslach_n = 0;
	fd = open(av, O_RDONLY);
	if (fd == 1)
		return (0);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (!test_nb_lines(buf))
			return (0);
		else
			backslach_n += test_nb_lines(buf);
		if (!test_chars(buf))
			return (0);
		nb_tetriminos++;
	}
	if (backslach_n - nb_tetriminos * 4 != nb_tetriminos - 1)
		return (0);
	return (nb_tetriminos);
}
