/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:59:16 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/05 23:02:43 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	char	*check;
	long	*ptr;

	ptr = (long *)s;
	while (1)
	{
		check = (char *)ptr;
		if (!check[0])
			return (check - s);
		if (!check[1])
			return (check - s + 1);
		if (!check[2])
			return (check - s + 2);
		if (!check[3])
			return (check - s + 3);
		if (!check[4])
			return (check - s + 4);
		if (!check[5])
			return (check - s + 5);
		if (!check[6])
			return (check - s + 6);
		if (!check[7])
			return (check - s + 7);
		ptr++;
	}
}
