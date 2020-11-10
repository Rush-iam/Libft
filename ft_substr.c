/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:54:11 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/10 22:01:50 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*cur;

	if (!s || !len || !(substr = malloc(len + 1)))
		return (NULL);
	if (ft_strlen(s) > start)
	{
		s += start;
		cur = substr;
		while (len && *s)
		{
			*cur++ = *s++;
			len--;
		}
		*cur = 0;
	}
	else
		*substr = 0;
	return (substr);
}
