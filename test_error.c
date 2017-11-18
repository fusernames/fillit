/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:15:20 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/17 20:06:46 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	test_tet(char *buf)
{
	int i;
	int len;

	len = ft_strlen(buf);
	printf("%c %d", buf[20], len);
	if (buf[len - 1] != '\n')
		return (0);
	printf("a\n");
	if (!test_nb_lines(buf))
		return (0);
	printf("a\n");
	if (!test_tab(buf))
		return (0);
	printf("x\n");
	return (1);


}

int	test_error(char *str)
{
	int fd;
	int ret;
	char buf[22];
	int compteur;

	compteur = 0;
	fd = open(str, O_RDONLY);
	if (fd == 1)
		return (0);
	printf("a\n");
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		printf("lol");
		if (!test_tet(buf))
			return (0);
		compteur++;
	}
	return (1);
}
