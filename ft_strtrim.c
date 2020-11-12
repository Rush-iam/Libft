/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:49:30 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/11 22:59:37 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	ft_strchr_mod(const char c, char const *set)
{
	while (*set && *set != c)
		set++;
	return (*set);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	char		*cur;
	const char	*start;

	if (!s1)
		return (NULL);
	if (!set || !*set)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr_mod(*s1, set))
		s1++;
	if (!*s1)
		return (ft_calloc(1, 1));
	start = s1;
	while (*s1)
		s1++;
	while (ft_strchr_mod(*--s1, set))
		;
	if (!(str = malloc(s1 - start + 2)))
		return (NULL);
	cur = str;
	while (start <= s1)
		*cur++ = *start++;
	*cur = 0;
	return (str);
}
