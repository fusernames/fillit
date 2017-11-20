/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 04:44:47 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/20 09:12:14 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_space(t_tetri *lst, char **tab, int i, int j, int size)
{
	int		nb;

	size--;
	nb = 0;
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
	tab[i + lst->point[0].y][j + lst->point[0].x] = lst->c;
	tab[i + lst->point[1].y][j + lst->point[1].x] = lst->c;
	tab[i + lst->point[2].y][j + lst->point[2].x] = lst->c;
	tab[i + lst->point[3].y][j + lst->point[3].x] = lst->c;
}

static void		erase_c(char **tab, int size, char c)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] == c)
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

static void		go_to_char(t_tetri **tetris, char c)
{
	while ((*tetris)->next)
	{
		if ((*tetris)->c == c)
			break;
		*tetris = (*tetris)->next;
	}
}

int				place_tetriminos(char **tab, t_tetri **tetris, char c, int size)
{
	int i;
	int j;
	t_tetri		*start;

	i = 0;
	j = 0;
	start = *tetris;
	go_to_char(tetris, c);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] == '.' && check_space(*tetris, tab, i, j, size))
			{
				place_c(*tetris, tab, i, j);
				if ((*tetris)->next == NULL || place_tetriminos(tab, &start, c + 1, size))
					return (1);
				erase_c(tab, size, c);
			}
			j++;
		}
		i++;
	}
	return (0);
}
