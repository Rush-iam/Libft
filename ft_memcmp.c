/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:45:52 by ngragas           #+#    #+#             */
/*   Updated: 2021/02/02 21:50:08 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_memcmp_check_8(const void *s1, const void *s2)
{
	if (((char *)s1)[0] != ((char *)s2)[0])
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	if (((char *)s1)[1] != ((char *)s2)[1])
		return (*(unsigned char *)(s1 + 1) - *(unsigned char *)(s2 + 1));
	if (((char *)s1)[2] != ((char *)s2)[2])
		return (*(unsigned char *)(s1 + 2) - *(unsigned char *)(s2 + 2));
	if (((char *)s1)[3] != ((char *)s2)[3])
		return (*(unsigned char *)(s1 + 3) - *(unsigned char *)(s2 + 3));
	if (((char *)s1)[4] != ((char *)s2)[4])
		return (*(unsigned char *)(s1 + 4) - *(unsigned char *)(s2 + 4));
	if (((char *)s1)[5] != ((char *)s2)[5])
		return (*(unsigned char *)(s1 + 5) - *(unsigned char *)(s2 + 5));
	if (((char *)s1)[6] != ((char *)s2)[6])
		return (*(unsigned char *)(s1 + 6) - *(unsigned char *)(s2 + 6));
	return (*(unsigned char *)(s1 + 7) - *(unsigned char *)(s2 + 7));
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n >= 16)
	{
		if (*(__uint128_t *)s1 ^ *(__uint128_t *)s2)
			return (*(size_t *)s1 ^ *(size_t *)s2 ?
				ft_memcmp_check_8(s1, s2) : ft_memcmp_check_8(s1 + 8, s2 + 8));
		s1 += 16;
		s2 += 16;
		n -= 16;
	}
	if (n >= 8)
	{
		if (*(size_t *)s1 ^ *(size_t *)s2)
			return (*(unsigned int *)s1 ^ *(unsigned int *)s2 ?
				ft_memcmp_check_8(s1, s2) : ft_memcmp_check_8(s1 + 4, s2 + 4));
		s1 += 8;
		s2 += 8;
		n -= 8;
	}
	if (!n)
		return (0);
	while (--n && *(char *)s1 == *(char *)s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
