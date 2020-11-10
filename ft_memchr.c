/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:46:42 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/10 15:30:23 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n && *(char *)s != (char)c)
	{
		s++;
		n--;
	}
	return (n ? (void *)s : NULL);
}
