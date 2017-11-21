/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:51:04 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/16 02:19:12 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s) - 1;
	while (ft_isspace(s[start]))
		start++;
	while (ft_isspace(s[end]) && end >= -1)
		end--;
	if (s[start] == '\0')
		start = 0;
	if (!(new = ft_strnew(end - start + 1)))
		return (NULL);
	while (i + start <= end)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
