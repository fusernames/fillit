/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:54:23 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/11 20:22:21 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	s1_char = (unsigned char *)s1;
	s2_char = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_char[i] != s2_char[i])
			return (s1_char[i] - s2_char[i]);
		i++;
	}
	return (0);
}
