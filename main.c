/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:19:37 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/21 06:00:14 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_tetri		*lst;
	char		**tab;
	int			size;
	int			nb_tetriminos;

	nb_tetriminos = 0;
	tab = create_tab(12);
	lst = NULL;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit tetriminos_map_file\n");
		return (0);
	}
	if ((nb_tetriminos = check_tetriminos(av[1])))
	{
		size = ft_sqrt(nb_tetriminos * 4);
		lst = create_tetriminos(av[1]);
		while (!resolve(tab, &lst, 'A', size))
			size++;
		print_tab(tab, size);
		cleanup(tab);
	}
	else
		ft_putstr("error\n");
	return (0);
}
