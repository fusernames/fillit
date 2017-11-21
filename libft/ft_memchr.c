/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:38:32 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/12 15:29:51 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_char;

	i = 0;
	s_char = (unsigned char*)s;
	while (i < n)
	{
		if (s_char[i] == (unsigned char)c)
			return ((void*)&s[i]);
		i++;
	}
	return (NULL);
}
