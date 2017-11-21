/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:10:57 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/15 03:21:24 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_recursive(long nb, int fd)
{
	if (nb >= 10)
	{
		putnbr_recursive(nb /= 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	putnbr_recursive(nb, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
