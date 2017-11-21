/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 22:57:47 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/19 04:54:31 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getsize(long *n, int *isnegative)
{
	int		i;
	long	tmp;

	i = 0;
	if (*n == 0)
		return (1);
	if (*n < 0)
	{
		*n = -(*n);
		*isnegative = 1;
		i++;
	}
	tmp = *n;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	nb;
	char	*str;
	size_t	size;
	int		isnegative;

	nb = n;
	isnegative = 0;
	size = getsize(&nb, &isnegative);
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		size--;
		str[size] = (nb % 10) + '0';
		nb /= 10;
	}
	if (isnegative)
		str[0] = '-';
	return (str);
}
