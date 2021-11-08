/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:45:16 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/25 10:07:40 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

void	ft_ss_rr_rrr(t_param *val, char *c)
{
	if (val->size_a > 1 && val->size_b > 1)
	{
		if ((!ft_strncmp("sa", c, 2) && val->head_b->content
				< val->head_b->next->content) || (!ft_strncmp("sb", c, 2)
				&& val->head_a->content > val->head_a->next->content))
			c = "ss";
	}
	if (val->size_a > 1 && val->size_b > 1)
	{
		if ((!ft_strncmp("ra", c, 2) && val->head_b->content
				< val->tail_b->content) || (!ft_strncmp("rb", c, 2)
				&& val->head_a->content > val->tail_a->content))
			c = "rr";
	}
	if (val->size_a > 1 && val->size_b > 1)
	{
		if ((!ft_strncmp("rra", c, 3) && val->head_b->content
				< val->tail_b->content) || (!ft_strncmp("rrb", c, 3)
				&& val->head_a->content > val->tail_a->content))
			c = "rrr";
	}
}
