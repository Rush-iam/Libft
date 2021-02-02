/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:17:16 by ngragas           #+#    #+#             */
/*   Updated: 2021/02/02 14:25:29 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*cur;
	const size_t	int64 = 0x0101010101010101 * (unsigned char)c;
	__uint128_t		int128;

	cur = b;
	if (len >= 16)
	{
		int128 = int64 | ((__uint128_t)int64 << 64);
		while (len >= 16)
		{
			*(__uint128_t *)cur = int128;
			cur += 16;
			len -= 16;
		}
	}
	if (len >= 8)
	{
		*(size_t *)cur = int64;
		cur += 8;
		len -= 8;
	}
	while (len--)
		*cur++ = (char)c;
	return (b);
}
