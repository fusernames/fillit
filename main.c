/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:19:37 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/19 06:10:37 by alcaroff         ###   ########.fr       */
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
	if (ac != 2)
	{
		ft_putstr("usage: ..\n");
		return (0);
	}
	if (!check_tetriminos(av[1]))
		ft_putstr("error\n");
	else
		;// creer les tetris
	return (0);
}
