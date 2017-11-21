/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 05:44:38 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/21 05:45:42 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

void	cleanup(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**create_tab(int size)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = (char **)malloc(sizeof(*tab) * (size + 1));
	tab[size] = NULL;
	while (i < size)
	{
		tab[i] = (char *)malloc(sizeof(char) * (size + 1));
		tab[i][size] = '\0';
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

void	print_tab(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
