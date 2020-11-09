/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:33:07 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/05 20:28:55 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		len;
	const char	*start;

	start = dst;
	while (dstsize && *dst)
	{
		dstsize--;
		dst++;
	}
	if (dstsize)
	{
		while (--dstsize && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	len = dst - start;
	start = src;
	while (*src++)
		;
	return (src - start + len - 1);
}
