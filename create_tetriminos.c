/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 08:10:39 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/19 09:41:44 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * CREATE_TETRIMINOS
 * creer les tetrimino en les ajoutant dans une liste
 */

t_tetri			create_tetriminos(char *av)
{
	t_tetri		*start;
	int			fd;
	char		buf[22];
	int			ret;

	fd = open(av, O_RDONLY);
	if (fd == 1)
		return (0);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		start = new_tetrimino(start, buf);
	}
	printf("OK : \n");
	return (start);
}

static t_tetri	*new_tetrimino(t_tetri *tetrimino, char const *buf)
{
	t_tetri		*start;
	t_tetri		*new;
	int			i;
	int			j;
	int			nb;
	char		c;
	
	i = 0;
	nb = 0;
	start = tetrimino;
	while (tetrimino && tetrimino->next != NULL)
		tetrimino = tetrimino->next;
	new = (t_tetri *)malloc(sizeof(t_tetri));
	new->point[0]->y = 0;
	new->point[0]->x = 0;
	while (*buf != '#')
	{
		i++;
		buf++;
	}
	while (buf[j])
	{
		if (buf == '#')
		{
			new->point[nb]->x = (j % 5) - (i % 5);
			new->point[nb]->y = (j / 5) - (i / 5);
			nb++;
		}
		j++;	
	}
	if (start == NULL)
		start = new;
	return(start);
}
