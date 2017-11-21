/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 23:22:45 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/15 02:04:18 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	while (s_len > 0)
	{
		if (s[s_len] == c)
			return ((char *)&s[s_len]);
		s_len--;
	}
	if (s[s_len] == c)
		return ((char *)&s[s_len]);
	return (NULL);
}
