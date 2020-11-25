/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:09:30 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/25 12:18:43 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char   *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	j = 0;
	if (!(*needle) || !len)
		return ((char*)haystack);
	if (!(*haystack) || ft_strlen(needle) > len)
		return (NULL);
	while (haystack[j] && j < len)
	{
		i = 0;
		while (needle[i] == haystack[j + i] && j + i < len && j + i <
		        										ft_strlen(haystack))
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack + j);
		j++;
	}
	return (NULL);
}
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*check_haystack;
	const char	*check_needle;
	size_t		needle_len;

	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	if (!len || (*haystack && len < needle_len))
		return (NULL);
	len -= needle_len - 1;
	while (len && *haystack)
	{
		if (*haystack == *needle)
		{
			check_haystack = haystack + 1;
			check_needle = needle + 1;
			while (*check_needle && *check_haystack++ == *check_needle)
				check_needle++;
			if (!*check_needle)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
