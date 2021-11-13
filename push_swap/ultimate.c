/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:23:37 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/13 19:39:24 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_ultimate(t_param *val, t_node *a)
{
	t_node	*aux;

	ft_aux_up(val, 0);
	ft_aux_down(val, 0, val->head_a);
	val->chunk_size = ft_new_node(val->size_a);
	aux = val->chunk_size;
	while (aux->next != NULL)
		aux = aux->next;
	ft_delnode(&val->chunk_size, aux);
	val->less = 0;
	while (a->next != NULL)
	{
		if (ft_calculate(val->head_a, a, val->head_a->content, 1) > val-> less)
		{
			val->less = ft_calculate(val->head_a, a, val->head_a->content, 1);
			val->current = a->content;
		}
		a = a->next;
	}
	ft_best_nbrs(val, val->head_a, val->head_a, 1);
	ft_pass_to_b(val, val->head_a, val->pass_b);
	while (val->size_b)
		ft_final_pass(val, val->head_b);
}

int	ft_calculate(t_node *head, t_node *a, int first, int count)
{
	int	reference;

	reference = a->content;
	while (a->next != NULL)
	{
		if (a->content > reference)
		{
			reference = a->content;
			count++;
		}
		a = a->next;
	}
	while (head->content != first)
	{
		if (head->content > reference)
		{
			reference = head->content;
			count++;
		}
		head = head->next;
	}
	return (count);
}

void	ft_best_nbrs(t_param *val, t_node *head, t_node *a, int count)
{
	int	first;

	while (a->content != val->current)
		a = a->next;
	val->pass_b = ft_new_node(val->current);
	first = a->content;
	val->reference = a->content;
	while (a->next != NULL)
	{
		if (a->content > val->reference && count ++)
		{
			val->reference = a->content;
			ft_addback(&val->pass_b, a->content);
		}
		a = a->next;
	}
	while (head->content != first)
	{
		if (head->content > val->reference && count++)
		{
			val->reference = head->content;
			ft_addback(&val->pass_b, head->content);
		}
		head = head->next;
	}
}
