/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:24:30 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/18 10:08:03 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
/* printf */
# include <stdio.h>

int					test_error(char *str);
int					test_tet(char *buf);
int					test_tab(char * buf);
int					test_nb_lines(char *buf);
char				**ft_strsplit(char const *s, char c);
unsigned int		ft_strlen(const char *str);
unsigned int		ft_charoc(const char *str, char c);

#endif
