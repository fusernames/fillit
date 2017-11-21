/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:56:48 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/15 23:00:12 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	dup = ft_strnew(n);
	if (dup == NULL)
		return (NULL);
	ft_strncpy(dup, str, n);
	return (dup);
}
