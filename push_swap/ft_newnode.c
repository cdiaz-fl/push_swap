/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:40:27 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/07 13:06:52 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"
#include	<stdlib.h>

void	ft_addfront(t_node **head, int content)
{
	t_node	*new;

	if (head)
	{		
		new = malloc(sizeof(t_node));
		new->content = content;
		new->next = *head;
		*head = new;
	}
}

void	ft_addmiddle(t_node **head, int content, int position)
{
	t_node	*aux;
	t_node	*follow;
	t_node	*new;
	int		i;

	i = 1;
	aux = *head;
	if (head)
	{
		new = malloc(sizeof(t_node));
		new->content = content;
		while (i < position && head != NULL)
		{
			i++;
			if (i == position)
				break ;
			aux = aux->next;
		}
		follow = aux->next;
		aux->next = new;
		new->next = follow;
	}
}

void	ft_addback(t_node	**head, int content)
{
	t_node	*tmp;
	t_node	*new;

	if (head)
	{
		new = malloc(sizeof(t_node));
		new->content = content;
		tmp = *head;
		while (tmp != NULL)
		{
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->next = NULL;
	}
}

void	ft_delnode(t_node **head, t_node *node)
{
	t_node	*tmp;
	t_node	*aux;

	tmp = *head;
	if (tmp && node && tmp == node && tmp->next != NULL)
	{
		tmp = tmp->next;
		*head = tmp;
	}
	else if (tmp && node && tmp != node && tmp->next != NULL)
	{
		while (tmp->next != node)
			tmp = tmp->next;
		aux = node->next;
		tmp->next = aux;
	}
	else if (tmp && node && tmp != node && tmp->next == NULL)
	{
		while (tmp->next != node)
			tmp = tmp->next;
		tmp->next = NULL;
	}
	else if (tmp && node && tmp == node && tmp->next == NULL)
		*head = NULL;
	free(node);
}

void	ft_freelst(t_node **head)
{
	t_node	*tmp;
	t_node	*aux;

	aux = *head;
	while (aux != NULL)
	{
		tmp = aux->next;
		free(aux);
		aux = tmp;
	}
	*head = NULL;
}
