/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:31:25 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/21 09:33:28 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

void	ft_sort_a(t_param *val)
{
	int i;

	i = 0;
	while (i < (val->aux_size / 2))
	{
		if (val->head_a->content < val->piv)
			ft_p(val, "pb");
		else if (val->tail_a->content < val->piv)
		{
			ft_rr(val, "rra");
			ft_p(val, "pb");
		}
		else
		{
			ft_r(val, "ra");
			i--;
		}
		i++;
	}
	ft_addfront(&val->chunk_size, i);
}

int	ft_bigger(t_node *head)
{
	int	bigger;
	t_node	*tmp;

	tmp = head;
	bigger = -2147483648;
	while (tmp != NULL)
	{
		if (tmp->content > bigger)
			bigger = tmp->content;
		tmp = tmp->next;
	}
	return (bigger);
}

void	ft_final(t_param *val)
{
	ft_aux_up(val, 0);
	ft_aux_down(val, 0);
	val->chunk_size = ft_new_node(val->size_a);
	val->chunk_size_b = ft_new_node(val->size_a);
	while (val->size_a > 2)
	{
		if (val->chunk_size->content / 2 == 0)
			val->piv =	ft_get_aux(val->aux_up, val->size_a / 2 + 1, val);
		else
			val->piv =	ft_get_aux(val->aux_up, val->size_a / 2, val);
		val->aux_size = val->size_a;
		ft_sort_a(val);
	}
	ft_delnode(&val->chunk_size, ft_lstend(&val->chunk_size));			
	if (val->head_a->content > val->head_a->next->content)
			ft_s(val, "sa");


	while (!ft_sort(val->head_a) || !ft_desort(val->head_b, val->size_b))
	{

		ft_second(val);
		ft_freelst(&val->chunk_size);
		val->chunk_size = ft_new_node(val->size_a);
		if (val->size_b == 0)
			break ;
		ft_almost(val);
		ft_freelst(&val->chunk_size_b);
		val->chunk_size_b = ft_new_node(val->size_a);
		if (val->size_b == 0)
			break ;
			
	}
	while (val->size_b > 0)
		ft_p(val, "pa");
	
}
