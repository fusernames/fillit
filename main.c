/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:19:37 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/20 10:05:29 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** MAIN
** 1. verifie que les tetriminos sont valides via CHECK_TETRIMINOS
** 2. si c'est le cas, creer les tetriminos et retourne le debut de liste via CREATE_TETRIMINOS
** 3. lance la resolution avec pour parametre le debut liste
** 4. afficher le resultat
*/

int			ft_sqrt(int nb)
{
	int i;

	i = 2;
	while (i * i < nb)
		i++;
	ft_putnbr(i);
	return (i);

}

void		cleanup(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static char	**create_tab(int size)
{
	char	**tab;
	int		i = 0;
	int		j;

	tab = (char **)malloc(sizeof(*tab) * (size + 1));
	tab[size] = NULL;
	while(i < size)
	{
		tab[i] = (char *)malloc(sizeof(char) * (size + 1));
		tab[i][size] = '\0';
		j = 0;
		while(j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

static void	print_tab(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while(i < size)
	{
		j = 0;
		while(j < size)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int			main(int ac, char **av)
{
	t_tetri		*lst;
	char		**tab;
	int			size;
	int			nb_tetriminos;

	nb_tetriminos = 0;
	tab = create_tab(40);
	lst = NULL;
	if (ac != 2)
	{
		ft_putstr("usage: ..\n");
		return (0);
	}
	if ((nb_tetriminos = check_tetriminos(av[1])))
	{
		size = ft_sqrt(nb_tetriminos * 4);
		lst = create_tetriminos(av[1]);
		while (!place_tetriminos(tab, &lst, 'A', size))
			size++;
		print_tab(tab, size);
		cleanup(tab);
	}
	else
		ft_putstr("error\n");
	return (0);
}
