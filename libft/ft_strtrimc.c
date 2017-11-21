/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:40:09 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/16 00:41:58 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	int		start;
	int		end;
	char	*new;
	int		i;

	if (s == NULL)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == c)
		start++;
	while ((s[end] == c) && end >= -1)
		end--;
	if (s[start] == '\0')
		start = 0;
	if ((new = ft_strnew(end - start + 1)) == NULL)
		return (NULL);
	while (i + start <= end)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
