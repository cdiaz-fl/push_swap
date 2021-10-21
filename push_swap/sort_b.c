/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:46:23 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/21 09:54:54 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

void	ft_almost(t_param *val)
{
	ft_sort_b_final(val, 0);
	if (val->size_b == 2 && val->head_b->content < val->head_b->next->content)
		ft_s(val, "sb");

}

void	ft_sort_b_final(t_param *val, int ra)
{
	t_node	*copy;

	copy = val->chunk_size_b;
	while (val->size_a > 2 && ft_deorder_size(val, val->head_a))
	{
		val->count_f_chk = 0;
		if (val->size_a > 2 && copy->content % 2 == 0)
			val->piv = ft_take_piv(val, copy->content / 2, val->head_a, 1);
		else if (val->size_a > 2)
			val->piv = ft_take_piv(val, copy->content / 2 + 1, val->head_a, 0);
		while (val->size_a > 2 && !ft_bd(val->piv, val->head_a) && copy->content > 2)
		{
			if (val->head_a->content < val->piv)
				ft_pass_b(val, ra, 0);
			else
			{
				ft_r(val, "ra");
				ra++;
			}
		}
		ft_pass_b(val, ra, 1);
		ra = 0;
		if (copy->content <= 2)
			ft_previous_b(val);
		ft_addfront(&val->chunk_size, val->count_f_chk);
		copy->content -= val->count_f_chk;
		if (copy->content == 0)
			copy = copy->next;
	}
	copy->content = 0;
}


int	ft_pass_b(t_param *val, int ra, int on)
{
	if (!on)
	{
		ft_p(val, "pb");
		val->count_f_chk += 1;
	}
	while (ra && on)
	{
		ft_rr(val, "rra");
		ra--;
	}
	return (ra);
}

void	ft_previous_b(t_param *val)
{
	if (val->head_a->content < val->head_a->next->content)
	{
		ft_p(val, "pb");
		val->count_f_chk++;
	}
	else if (val->size_a > 2) 
	{
		ft_s(val, "sa");
		ft_p(val, "pb");
		ft_p(val, "pb");
		val->count_f_chk += 2;
	}
}

