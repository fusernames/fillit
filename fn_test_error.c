/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_test_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:51:12 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/17 19:58:21 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	test_nb_lines(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if ((i + 1) % 5 == 0 && buf[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int test_tab(char * buf)
{
	char **tab;
	int i;
	int j;
	int side_hash;
	int nb_tot;

	i = 0;
	side_hash = 0;
				printf("b\n");
	nb_tot = 0;
	tab = ft_strsplit(buf, '\n');
				printf("b\n");
	while (tab[i])
	{
		j = 0;
				printf("b\n");
		while (tab[i][j])
		{
			if (tab[i][j] != '.' && tab[i][j] != '#')
				return (0);
			if (tab[i][j] == '#')
			{
				printf("b\n");
				if (i > 0 && tab[i - 1][j] == '#')
					side_hash = 1;
				if (i < 3 && tab[i + 1][j] == '#')
					side_hash = 1;
				if (j > 0 && tab[i][j - 1] == '#')
					side_hash = 1;
				if (j < 3 && tab[i][j + 1] == '#')
					side_hash = 1;
				if (side_hash)
					nb_tot++;
			}
			j++;
		}
		i++;
	}
	printf("nbtot=%d", nb_tot);
	if (nb_tot == 4)
		return (1);
	else
		return (0);
}
			
