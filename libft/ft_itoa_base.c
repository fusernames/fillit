/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:32:09 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/15 21:58:33 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		getbase(char *str, long nb, int base, int size)
{
	char	*str_base;

	str_base = "0123456789ABCDEF";
	size--;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[size--] = str_base[nb % base];
		nb /= base;
	}
}

static size_t	getsize(long *nb, int *isnegative, int base)
{
	size_t	size;
	long	nb_cpy;

	if (nb == 0)
		return (1);
	size = 0;
	if (*nb < 0)
	{
		*nb = -*nb;
		if (base == 10)
		{
			*isnegative = 1;
			size++;
		}
	}
	nb_cpy = *nb;
	while (nb_cpy > 0)
	{
		nb_cpy /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base(int n, int base)
{
	long	nb;
	char	*str;
	size_t	size;
	int		isnegative;

	isnegative = 0;
	nb = n;
	size = getsize(&nb, &isnegative, base);
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	getbase(str, nb, base, size);
	if (isnegative)
		str[0] = '-';
	return (str);
}
