/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:23:37 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/12 18:58:01 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_printlst(t_node	**head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		//printf("%d - ", tmp->content);
		tmp = tmp->next;
	}
	//printf("\n\n");
}

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
	ft_printlst(&val->chunk_size);	
	val->less = 0;
	while (a->next != NULL)
	{
		if (ft_calculate(val->head_a, a) > val-> less)
		{
			val->less = ft_calculate(val->head_a, a);
			val->current = a->content;
		}
		a = a->next;
	}
	ft_best_nbrs(val, val->head_a, val->head_a);
	ft_pass_to_b(val, val->head_a, val->pass_b);
	while (val->size_b)
		ft_final_pass(val, val->head_b);
	
/*
	if (ft_sort(val->head_a))
			//printf("\nOKKKKKKKKK\n");
	else
			//printf("\nFATAAAAAAAAAAAAAAAL\n");
*/
}

int ft_calculate(t_node *head, t_node *a)
{
	int	first;
	int	count;
	int	reference;

	count = 1;
//	//printf("\n el número %d  ", a->content);
	first = a->content;
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
	//printf(" tiene  %d  \n", count);
	return (count);
}

void	ft_best_nbrs(t_param *val, t_node *head, t_node *a)
{
	int	first;
	int	count;
	int	reference;

	while (a->content != val->current)
		a = a->next;
	val->pass_b = ft_new_node(val->current);
	count = 1;
	first = a->content;
	reference = a->content;
	while (a->next != NULL)
	{
		if (a->content > reference)
		{
			reference = a->content;
			count++;
			ft_addback(&val->pass_b, a->content);
		}
		a = a->next;
	}
	while (head->content != first)
	{
		if (head->content > reference)
		{
			reference = head->content;
			count++;
			ft_addback(&val->pass_b, head->content);
		}
		head = head->next;
	}
	//printf("los que pasan a b son  ");
	ft_printlst(&val->pass_b);	
}
