/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:14:18 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/11 17:26:05 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	if ((dup = (char *)malloc((ft_strlen(s) + 1))) == NULL)
		return (NULL);
	ft_strcpy(dup, s);
	return (dup);
}
