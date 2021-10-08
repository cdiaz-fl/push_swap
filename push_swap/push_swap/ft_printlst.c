/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:54:32 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/06 14:43:26 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

void	ft_printlst(t_node	**head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d - ", tmp->content);
		tmp = tmp->next;
	}
}
