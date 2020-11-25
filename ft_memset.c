/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:17:16 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/21 23:51:26 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*ft_memset(void *b, int c, size_t len)
{
	char	*cur;

	cur = b;
	while (len--)
		*cur++ = c;
	return (b);

}
*/
void	*ft_memset(void *b, int c, size_t len)
{
	char			*cur;
	const unsigned	t1 = (unsigned char)c | ((unsigned char)c << 8);
	size_t			num;
	unsigned char	chars;

	num = t1 | t1 << 16;
	num |= num << 32;
	cur = b;
	chars = len % 8;
	len /= 8;
	while (len--)
	{
		*(size_t *)cur = num;
		cur += 8;
	}
	while (chars--)
		*cur++ = c;
	return (b);
}
