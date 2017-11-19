/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:03:31 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/18 10:08:39 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_charoc(const char *str, int c)
{
	unsigned int	res;

	res = 0;
	while (str++)
		if (*str == c)
			res++;
	return (res);
}