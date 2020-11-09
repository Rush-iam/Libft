/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:09:30 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/09 14:25:55 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*check_haystack;
	const char	*check_needle;

	if (!*needle)
		return ((char *)haystack);
	while (len && *haystack)
	{
		if (*haystack == *needle)
		{
			check_haystack = haystack + 1;
			check_needle = needle + 1;
			while (*check_needle && *check_haystack++ == *check_needle)
				check_needle++;
			if (!*check_needle && (size_t)(check_needle - needle) <= len)
				return ((char *)haystack);
		}
		len--;
		haystack++;
	}
	return (NULL);
}
