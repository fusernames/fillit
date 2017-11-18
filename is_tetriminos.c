/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:23:15 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/18 13:18:52 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * IS_TERMINOS
 * is_tetriminos lance tous les tests sur le buf et retourne 1 si tout est valide
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

static int	test_chars(char *buf)
{
	char	**lines;
	int		y;
	int		x;

	y = 0;
	x = 0;
	line = ft_strsplit(buf);
	if (ft_charoc(buf, '#') != 4)
		return (0);
	while(line[y])
	{
		while(line[y][x])
		{
			if (line[y][x] != '.' || line[y][x] != '#')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int			is_tetriminos(char *av)
{
	int		fd;
	char	buf[22];

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
	}
	return (1);
}
