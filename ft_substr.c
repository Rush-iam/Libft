/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:54:11 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/11 16:46:13 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*cur;
	size_t	src_len;

	if (!s || !len)
		return (NULL);
	src_len = ft_strlen(s);
	if (src_len > start)
	{
		src_len -= start;
		len = (len < src_len ? len : src_len) + 1;
		if (!(substr = malloc(len)))
			return (NULL);
		cur = substr;
		s += start;
		while (--len)
			*cur++ = *s++;
		*cur = 0;
	}
	else
		return (ft_calloc(1, 1));
	return (substr);
}
