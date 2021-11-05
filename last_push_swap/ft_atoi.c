/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:39:30 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/25 17:07:49 by cdiaz-fl         ###   ########.fr       */
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
	return (i * multi);
}

long	ft_real_atoi(const char *nptr)
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
	return (i * multi);
}
