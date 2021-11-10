/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 06:36:19 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/10 08:07:51 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_sort_three(t_param *val, int chunks)
{
	if (chunks == 1)
		ft_p(val, "pa");
	else if (chunks == 2
		&& val->head_b->content > val->head_b->next->content)
	{
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (chunks == 2)
	{
		ft_s(val, "sb");
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else
		ft_three_chk_1_b(val, val->head_b->content, val->head_b->next->content, 4);
}

void	ft_three_chk_1_b(t_param *val, int x, int y, int aux)
{
	int	z;

	z = val->head_b->next->next->content;
	if (x < y && y < z)			//1 2 3
	{
		ft_r(val, "rb");
		ft_s(val, "sb");
		ft_p(val, "pa");
		ft_p(val, "pa");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
	}
	else if (x < y && y > z && x < z)		// 1 3 2
	{
		ft_s(val, "sb");
		ft_p(val, "pa");
		ft_s(val, "sb");
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (x > y && y > z) // 3 2 1
		while (--aux)
			ft_p(val, "pa");
	else
		ft_three_chk_2_b(val, x, y, z);
}

void	ft_three_chk_2_b(t_param *val, int x, int y, int z)
{
	if (x > y && y < z && x > z) // 3 1 2
	{
		ft_p(val, "pa");
		ft_s(val, "sb");
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (x > y && y < z && x < z)	//2 1 3
	{
		ft_r(val, "rb");
		ft_s(val, "sb");
		ft_p(val, "pa");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (x < y && y > z && x > z) //2 3 1
	{
		ft_s(val, "sb");
		ft_p(val, "pa");
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
}













void	ft_sort_three_a(t_param *val, int chunks)
{
	if (chunks == 1)
		return ;
	else if (chunks == 2 && val->head_a->content < val->head_a->next->content)
		return ;
	else if (val->chunk_size_b->content == 2)
		ft_s(val, "sa");
	else
		ft_three_chk_1_a(val, val->head_a->content, val->head_a->next->content);
}

void	ft_three_chk_1_a(t_param *val, int x, int y)
{
	int	z;

	z = val->head_a->next->next->content;
	if (x < y && y < z)			//1 2 3
		return ;
	else if (x < y && y > z && x < z)		// 1 3 2
	{
		ft_r(val, "ra");
		ft_s(val, "sa");
		ft_rr(val, "rra");
	}
	else if (x > y && y > z) // 3 2 1
	{
		ft_s(val, "sa");
		ft_r(val, "ra");
		ft_s(val, "sa");
		ft_rr(val, "rra");
		ft_s(val, "sa");
	}
	else
		ft_three_chk_2_a(val, x, y, z);
}

void	ft_three_chk_2_a(t_param *val, int x, int y, int z)
{
	if (x > y && y < z && x > z) // 3 1 2
	{
		ft_s(val, "sa");
		ft_r(val, "ra");
		ft_s(val, "sa");
		ft_rr(val, "rra");
	}
	else if (x > y && y < z && x < z)	//2 1 3
		ft_s(val, "sa");
	else if (x < y && y > z && x > z) //2 3 1
	{
		ft_r(val, "ra");
		ft_s(val, "sa");
		ft_rr(val, "rra");
		ft_s(val, "sa");
	}
}
