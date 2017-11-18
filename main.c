/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:19:37 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/18 13:22:39 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * MAIN
 * 1. verifie que le fichier des tetriminos est valide
 * 2. si il l'est creer les tetris et les ajoutent a la liste
 * 3. appel d'une fonction qui s'occupera de realiser tous les tests et de retourner le resultat
 * 4. afficher le resultat 
 */
int		main(int ac, char **av)
{
	char		buf[22];
	int			ret;
	int			fd;

	if (ac != 1)
		ft_putstr("usage: ..\n");
	if (!is_tetriminos(av[1]))
		ft_putstr("error\n");
	else
		;// creer les tetris
	return (0);
}
