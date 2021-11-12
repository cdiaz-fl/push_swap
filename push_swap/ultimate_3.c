/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:56:05 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/12 18:59:17 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_pass_a(t_param *val)
{
	int	min;
	t_node	*a;
	int i;

	if (val->best == 'a')
	{
		while (val->rb > val->ra)
		{
			ft_r(val, "rb");
			val->rb--;
		}
		while (val->ra > val->rb)
		{
			ft_r(val, "ra");
			val->ra--;
		}
		while (val->rb || val->ra)
		{
			ft_r(val, "rr");
			val->ra--;
			val->rb--;
		}
	}
	else if (val->best == 'b')
	{
		while (val->rrb > val->rra)
		{
			ft_rr(val, "rrb");
			val->rrb--;
		}
		while (val->rra > val->rrb)
		{
			ft_rr(val, "rra");
			val->rra--;
		}
		while (val->rrb || val->rra)
		{
			ft_rr(val, "rrr");
			val->rra--;
			val->rrb--;
		}
	}
	else if (val->best == 'c')
	{
		while (val->rb)
		{
			ft_r(val, "rb");
			val->rb--;
		}
		while (val->rra)
		{
			ft_rr(val, "rra");
			val->rra--;
		}
		
	}
	else if (val->best == 'd')
	{
		while (val->rrb)
		{
			ft_rr(val, "rrb");
			val->rrb--;
		}
		while (val->ra)
		{
			ft_r(val, "ra");
			val->ra--;
		}
		
	}
	ft_p(val, "pa");
	if (val->head_b == 0)
	{
		min = ft_smaller(val->head_a);
		a = val->head_a;
		i = 0;
		while (a->content != min && ++i)
			a = a->next;
		if (i <= val->size_a / 2)
		{
			while (!ft_sort(val->head_a))
					ft_r(val, "ra");
		}
		else
		{
			while (!ft_sort(val->head_a))
					ft_rr(val, "rra");
		}
	}
}
