/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:24:30 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/21 06:14:28 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetri
{
	char			c;
	t_point			point[4];
	struct s_tetri	*next;
}				t_tetri;

void			cleanup(char **tab);
int				ft_sqrt(int nb);
char			**create_tab(int size);
void			print_tab(char **tab, int size);

int				check_tetriminos(char *av);
t_tetri			*create_tetriminos(char *av);
int				resolve(char **tab, t_tetri **tetris, char c, int size);

#endif
