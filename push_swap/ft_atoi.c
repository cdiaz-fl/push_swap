/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:40:38 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/09/29 16:41:29 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

int	ft_atoi(const char *nptr)
{
	long	i;
	long	multi;

	multi = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			multi = -1;
		nptr++;
	}
	i = 0;
	while (*nptr >= 48 && *nptr <= 57)
	{
		i *= 10;
		i += (*nptr - '0');
		nptr++;
	}
	/*
	i *= multi;
	if (i > INT_MAX || i < INT_MIN)
	{
		write(1, "Error\n", 1);
		exit (1);
	}
	*/
	return (i * multi);
}
