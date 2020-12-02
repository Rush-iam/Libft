/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:17:16 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/25 18:31:31 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*cur;
	const unsigned	i = (unsigned char)c | (unsigned char)c << 8;
	__int128		int128;
	char			chars;

	int128 = (unsigned short)i | i << 16 | (size_t)i << 32 | (size_t)i << 48;
	int128 |= int128 << 64;
	cur = b;
	chars = len % 8;
	len /= 8;
	if (len % 2)
	{
		*(ssize_t *)cur = (ssize_t)int128;
		cur += 8;
		--len;
	}
	while (len)
	{
		*(__int128_t *)cur = int128;
		cur += 16;
		len -= 2;
	}
	while (chars--)
		*cur++ = (unsigned char)c;
	return (b);
}
