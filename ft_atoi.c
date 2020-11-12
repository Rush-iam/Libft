/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:29:16 by ngragas           #+#    #+#             */
/*   Updated: 2020/11/09 18:03:32 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		num;
	char	sign;

	num = 0;
	while ((8 < *str && *str < 14) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (47 < *str && *str < 58)
		num = num * 10 + (*str++ - '0') * sign;
	return (num);
}
