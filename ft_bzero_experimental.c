/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:13:21 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/25 18:49:54 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	char	step1;

	str = s;
	step1 = n % 8;
	n /= 8;
	if (n % 2)
	{
		*(ssize_t *)str = 0;
		str += 8;
		--n;
	}
	while (n)
	{
		*(__int128 *)str = 0;
		str += 16;
		n -= 2;
	}
	while (step1--)
		*str++ = 0;
}
