/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:34:17 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/13 19:15:41 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

void	ft_five_four(t_param *val)
{
	ft_p(val, "pb");
	ft_p(val, "pb");
	ft_three_nbrs(val);
}

void	ft_five_third(t_param *val)
{
	if (val->head_a->next->content > val->tail_b->content)
	{
		ft_p(val, "pa");
		ft_r(val, "ra");
		ft_p(val, "pa");
		ft_s(val, "sa");
	}
	if (val->head_a->next->content < val->tail_b->content)
	{
		ft_p(val, "pa");
		ft_r(val, "ra");
		ft_r(val, "ra");
		ft_p(val, "pa");
		ft_s(val, "sa");
		ft_rr(val, "rra");
	}
}

void	ft_five_second(t_param *val)
{
	if (val->head_a->next->content > val->head_b->content)
	{
		ft_p(val, "pa");
		ft_s(val, "sa");
		ft_p(val, "pa");
		ft_s(val, "sa");
	}
	if (val->head_a->next->content < val->tail_b->content)
	{
		ft_p(val, "pa");
		ft_rr(val, "rra");
		ft_s(val, "sa");
		ft_p(val, "pa");
		ft_rr(val, "rra");
		ft_rr(val, "rra");
	}
	else
		ft_five_second_last(val);
}

void	ft_five_first(t_param *val)
{
	if (val->tail_a->content > val->head_b->content)
	{
		if (val->head_a->next->content > val->head_b->content)
		{
			ft_p(val, "pa");
			ft_s(val, "sa");
			ft_p(val, "pa");
		}	
		if (val->head_a->next->content < val->head_b->content
			&& val->tail_a->content > val->head_b->content)
		{
			ft_p(val, "pa");
			ft_rr(val, "rra");
			ft_s(val, "sa");
			ft_r(val, "ra");
			ft_r(val, "ra");
			ft_p(val, "pa");
		}	
	}
	else
	{
		ft_p(val, "pa");
		ft_r(val, "ra");
		ft_p(val, "pa");
	}
}

void	ft_five_nbrs(t_param *val)
{
	ft_five_four(val);
	if (ft_sort(val->head_b))
		ft_s(val, "sb");
	if (val->head_a->content > val->head_b->content)
	{
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (val->head_a->content > val->tail_b->content)
		ft_five_first(val);
	else
	{
		if (val->tail_a->content < val->tail_b->content)
		{
			ft_p(val, "pa");
			ft_p(val, "pa");
			ft_r(val, "ra");
			ft_r(val, "ra");
		}
		if (val->tail_a->content > val->head_b->content)
			ft_five_second(val);
		ft_five_third(val);
	}
}
