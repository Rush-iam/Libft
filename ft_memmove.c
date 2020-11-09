/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:43:41 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/09 22:39:17 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cur;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		cur = dst;
		while (len--)
			*cur++ = *(char *)src++;
	}
	else if (dst > src)
	{
		dst += len;
		src += len;
		while (len--)
			*(char *)--dst = *(char *)--src;
	}
	return (dst);
}
