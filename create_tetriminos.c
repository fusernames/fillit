/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 08:10:39 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/19 13:35:40 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * CREATE_TETRIMINOS
 * creer les tetrimino en les ajoutant dans une liste
 */

static t_tetri	*new_tetrimino(t_tetri *tetrimino, char const *buf, char c)
{
	t_tetri		*start;
	t_tetri		*new;
	int			i;
	int			j;
	int			nb;
	
	i = 0;
	j = 0;
	nb = 0;
	start = tetrimino;
	if (tetrimino)
		while (tetrimino->next)
			tetrimino = tetrimino->next;
	new = (t_tetri *)malloc(sizeof(t_tetri));
	if (tetrimino)
		tetrimino->next = new;
	while (buf[j] != '#')
	{
		i++;
		j++;
	}
	new->c = c;
	new->next = NULL;
	printf("%d %d\n", new->point[0].y, new->point[0].x);
	j = 0;
	while (buf[j])
	{
		if (buf[j] == '#')
		{
			new->point[nb].x = (j % 5) - (i % 5);
			new->point[nb].y = (j / 5) - (i / 5);
			printf("%d %d\n", new->point[nb].y, new->point[nb].x);
			nb++;
		}
		j++;	
	}
	printf("\n");
	if (start == NULL)
		start = new;
	return(start);
}

t_tetri			*create_tetriminos(char *av)
{
	t_tetri		*start;
	int			fd;
	char		buf[22];
	int			ret;
	char		c;

	c = 'A';
	fd = open(av, O_RDONLY);
	start = NULL;
	if (fd == 1)
		return (NULL);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		start = new_tetrimino(start, buf, c);
		c++;
	}
	return (start);
}
