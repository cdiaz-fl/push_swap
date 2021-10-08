/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:35:09 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/08 20:28:44 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

int	ft_get_pivot(t_param *val, t_node *head, int size)
{
	t_node	*tmp;
	t_node	*tmp2;
	int	x;
	int	i;
	int	max;

	tmp2 = head->next;
	tmp = ft_new_node(head->content);
	i = 1;
	while (i < size && tmp2 != NULL)
	{
		ft_addback(&tmp, tmp2->content);
		tmp2 = tmp2->next;
		i++;
	}
	ft_printlst(&tmp);
	printf("\n\n");
	tmp2 = tmp;
	i = 1;
	//Mejorar este while
	while (i < (val->size_a/2))
	{
		while (i < (val->size_a/2) && tmp2 != NULL)
		{
			if (ft_b(tmp2, tmp))
			{
				ft_delnode(&tmp, tmp2);
				tmp2 = tmp;
				i++;
			}
			else
				tmp2 = tmp2->next;
		}
		tmp2 = tmp;
	}
	while (tmp2 != NULL)
	{
		if (ft_b(tmp2, tmp))
			x = tmp2->content;
		tmp2 = tmp2->next;
	}
	ft_printlst(&tmp);
	printf("piiiiiiiiiiiiiivot: %d\n", x);
	x = 0;
	max = val->size_b;
	/*
	while (tmp != NULL)
	{
		if (ft_b(val, head))
			max = tmp->content;
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp != NULL && i < (size/2))
	{
		if (tmp->content < max && 
			pivot = tmp->content;
		tmp = tmp->next;
		i++;
	}
	x /= size;
	*/
	ft_freelst(&tmp);
	return (x);
}

void	ft_large(t_param *val)
{
	int	i;

	i = 0;
	val->piv = ft_get_pivot(val, val->head_a, val->size_a);
	printf("pivot = %d\n", val->piv);
	while (i < (val->size_a / 2))
	{
		printf("pivot = %d\n", val->piv);
		if (val->head_a->content <= val->piv)
		{
			ft_p(val, "pb");
			ft_print_stacks(val);
		}
		if (val->tail_a->content <= val->piv)
		{
			ft_rr(val, "rra");
			ft_print_stacks(val);
			ft_p(val, "pb");
			ft_print_stacks(val);
		}
		else
		{
			ft_r(val, "ra");
			ft_print_stacks(val);
			i--;
		}
		i++;
	}




}
