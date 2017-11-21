/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:35:37 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/10 20:25:15 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	char			*ptr_char;

	i = 0;
	ptr_char = (char *)ptr;
	while (i < num)
	{
		ptr_char[i] = value;
		i++;
	}
	return (ptr);
}
