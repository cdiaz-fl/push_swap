/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:21:49 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/06/01 13:57:03 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	j = 0;
	while (ptr[j] != '\0')
		j++;
	if (c == '\0')
		return (&ptr[j]);
	while (s[i] != '\0')
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
