/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:56:05 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/13 17:30:18 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_pass_a(t_param *val)
{
	if (val->best == 'a')
		ft_option_a(val);
	else if (val->best == 'b')
		ft_option_b(val);
	else if (val->best == 'c')
		ft_option_c(val);
	else if (val->best == 'd')
		ft_option_d(val);
	ft_p(val, "pa");
	ft_last_rotate(ft_smaller(val->head_a), val->head_a, 0, val);
}

void	ft_option_a(t_param *val)
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

void	ft_option_b(t_param *val)
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

void	ft_option_c(t_param *val)
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

void	ft_option_d(t_param *val)
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
