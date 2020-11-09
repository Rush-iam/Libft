/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:38:41 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/09 20:50:15 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*start;

	if (!src)
		return (0);
	start = src;
	if (dstsize && dst)
	{
		while (--dstsize && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	while (*src++)
		;
	return (src - start - 1);
}
