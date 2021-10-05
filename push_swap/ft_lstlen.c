/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:15:21 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/09/29 10:14:06 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

int	ft_lstlen(t_node **head)
{
	t_node	*tmp;
	int			i;

	i = 1;
	tmp = *head;
	if (!tmp)
		return (0);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_node	*ft_lstend(t_node **head)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *head;
	if (!tmp)
		return (NULL);
	tmp2 = *head;
	tmp = tmp->next;
	if (!tmp)
		return (tmp2);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	return (tmp2);
}

t_node	*ft_new_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->content = content;
	node->next = NULL;
	return (node);
}

