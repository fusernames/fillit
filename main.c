/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:19:37 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/19 13:23:07 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * MAIN
 * 1. verifie que les tetriminos sont valides via CHECK_TETRIMINOS
 * 2. si c'est le cas, creer les tetriminos et retourne le debut de liste via CREATE_TETRIMINOS
 * 3. lance la resolution avec pour parametre le debut liste
 * 4. afficher le resultat 
 */

int		main(int ac, char **av)
{
	t_tetri		*lst;

	lst = NULL;
	if (ac != 2)
	{
		ft_putstr("usage: ..\n");
		return (0);
	}
	if (!check_tetriminos(av[1]))
		ft_putstr("error\n");
	else
		lst = create_tetriminos(av[1]);

	// TESTS
	/*int		i = 0;
	while(lst)
	{
		printf("c : %c\n", lst->c);
		while(i < 4)
		{
			printf("%d : %d %d\n", i, lst->point[i].y, lst->point[i].x);
			i++;
		}
		lst = lst->next;
	}*/
	// END TESTS
	
	return (0);
}
