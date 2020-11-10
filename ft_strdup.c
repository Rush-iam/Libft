/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:28:54 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/10 20:05:12 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	char	*cur;

	len = ft_strlen(s1) + 1;
	if (!(dup = malloc(len)))
		return (NULL);
	cur = dup;
	while (len--)
		*cur++ = *s1++;
	return (dup);
}
