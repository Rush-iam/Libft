/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:23:09 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/25 19:42:38 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cur;
	char	step1;

	if (!dst && !src)
		return (NULL);
	cur = dst;
	step1 = n % 8;
	n /= 8;
	if (n % 2)
	{
		*(ssize_t *)cur = *(ssize_t *)src;
		cur += 8;
		src += 8;
		--n;
	}
	while (n)
	{
		*(__int128 *)cur = *(__int128 *)src;
		cur += 16;
		src += 16;
		n -= 2;
	}
	while (step1--)
		*cur++ = *(char *)src++;
	return (dst);
}
