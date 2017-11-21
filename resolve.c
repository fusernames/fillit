/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 04:44:47 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/21 06:03:55 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_space(t_tetri *lst, int ij, int size, char **tab)
{
	int		nb;
	int		i;
	int		j;

	j = ij % 10;
	i = (ij / 10) % 10;
	size--;
	nb = 1;
	while (nb < 4)
	{
		if (i + lst->point[nb].y > size || j + lst->point[nb].x > size)
			return (0);
		if (tab[i + lst->point[nb].y][j + lst->point[nb].x] != '.')
			return (0);
		nb++;
	}
	return (1);
}

static void		place_c(t_tetri *lst, char **tab, int i, int j)
{
	tab[i][j] = lst->c;
	tab[i + lst->point[1].y][j + lst->point[1].x] = lst->c;
	tab[i + lst->point[2].y][j + lst->point[2].x] = lst->c;
	tab[i + lst->point[3].y][j + lst->point[3].x] = lst->c;
}

static void		erase_c(t_tetri *lst, char **tab, int i, int j)
{
	tab[i][j] = '.';
	tab[i + lst->point[1].y][j + lst->point[1].x] = '.';
	tab[i + lst->point[2].y][j + lst->point[2].x] = '.';
	tab[i + lst->point[3].y][j + lst->point[3].x] = '.';
}

static void		go_to_char(t_tetri **tetris, char c)
{
	while ((*tetris)->next)
	{
		if ((*tetris)->c == c)
			break ;
		*tetris = (*tetris)->next;
	}
}

int				resolve(char **tab, t_tetri **tetris, char c, int size)
{
	int			i;
	int			j;
	t_tetri		*start;

	i = 0;
	start = *tetris;
	go_to_char(tetris, c);
	while (i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (tab[i][j] == '.' && check_space(*tetris, (i * 10) + j,
						size, tab))
			{
				place_c(*tetris, tab, i, j);
				if ((*tetris)->next == NULL ||
						resolve(tab, &start, c + 1, size))
					return (1);
				erase_c(*tetris, tab, i, j);
			}
		}
		i++;
	}
	return (0);
}
