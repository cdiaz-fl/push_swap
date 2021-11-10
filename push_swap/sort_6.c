/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 06:53:49 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/10 08:51:10 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_sort_six(t_param *val, t_node *b, t_node *max, int chunk)
{
	int	i;

	i = val->size_a + 3;
	while (--i)
		max = max->next;
	while ((b->content < max->content || b->next->content < max->content
		|| b->next->next->content < max->content) && ++i)
	{
		if (b->content < max->content)
			ft_r(val, "rb");
		else if (b->next->content < max->content)
		{
			ft_s(val, "sb");
			ft_r(val, "rb");
		}	
		else if (b->next->next->content < max->content)
		{
			ft_r(val, "rb");
			ft_s(val, "sb");
			ft_rr(val, "rrb");
			ft_s(val, "sb");
			i--;
		}
		b = val->head_b;
	}
	ft_sort_six_1(val, chunk, i, val->head_b);
}

void	ft_sort_six_1(t_param *val, int chunk, int bottom, t_node *b)
{
	t_node	*reference;
	int	x;
	int	y;

	ft_sort_three(val, 3);
	b = val->head_b;
	reference = b;
	while (b->next != NULL && b->next->content != val->tail_b->content)
		b = b->next;
	y = b->content;
	b = reference;
	while (b->next != NULL && b->next->content != y)
		b = b->next;
	x = b->content;
	b = reference;
	printf("\n x es = %d \n", x);
	printf("\n y es = %d \n", y);
	printf("\n z es = %d \n", val->tail_b->content);
	if (bottom == 0)
		ft_sort_three(val, chunk - 3);
	else if (bottom == 1)
		ft_sort_six_2(val, chunk - 3, val->tail_b->content, val->head_b);
	else if (bottom == 2)
		ft_sort_six_3(val, chunk - 3, y, val->tail_b->content);
	else if (bottom == 3)
		ft_sort_six_4(val, x, y, val->tail_b->content);
}

void	ft_sort_six_2(t_param *val, int chunk, int z, t_node *b)
{
	if (chunk == 1)
	{
		ft_rr(val, "rrb");
		ft_p(val, "pa");
	}
	else if (chunk == 2)
	{
		if (b->content > z)
		{
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
		}
		else
		{
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_p(val, "pa");
		}
	}
	else if (chunk == 3)
	{
		if (b->content > b->next->content && b->next->content > z) // 3 2 - 1
		{
			ft_p(val, "pa");
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
		}
		else if (b->content > z && b->content < b->next->content) // 2 3 - 1
		{
			ft_s(val, "sb");
			ft_p(val, "pa");
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
		}
		else if (b->content > z && z > b->next->content) // 3 1 - 2
		{
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_p(val, "pa");
		}
		else if (b->content < z && z < b->next->content) // 1 3 - 2
		{
			ft_s(val, "sb");
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_p(val, "pa");
		}
		else if (b->content < z && b->content > b->next->content) // 2 1 - 3
		{
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_p(val, "pa");
			ft_p(val, "pa");
		}
		else if (b->content < b->next->content && b->content < z) // 1 2 - 3
		{
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_s(val, "sb");
			ft_p(val, "pa");
			ft_p(val, "pa");

		}
	}
}

void	ft_sort_six_3(t_param *val, int chunk, int y, int z)
{
	t_node	*b;

	b = val->head_b;
	if (chunk == 2)
	{
		if (z > y)
		{
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
		}
		else
		{
			ft_rr(val, "rrb");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_p(val, "pa");
		}
	}
	else if (chunk == 3)
	{
		if (b->content > z && z > y) // 3 - 2 1
		{
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
		}
		else if (b->content > z && z < y && b->content > y) // 3 - 1 2
		{
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_p(val, "pa");
		}
		else if (b->content > z && z < y && y > b->content) // 2 - 1 3
		{
			ft_rr(val, "rrb");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_s(val, "sb");
			ft_p(val, "pa");
			ft_p(val, "pa");

		}
		else if (b->content < z && z > y && b->content > y) // 2 - 3 1
		{
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
		}
		else if (b->content < z && z < y) // 1 - 2 3
		{
			ft_rr(val, "rrb");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_p(val, "pa");
			ft_p(val, "pa");
		}
		else if (b->content < z && z > y && y > b->content) // 1 - 3 2
		{
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_rr(val, "rrb");
			ft_p(val, "pa");
			ft_p(val, "pa");
		}
	}

}

void	ft_sort_six_4(t_param *val, int x, int y, int z)
{
	if (z > y && y > x) // 3 2 1
	{
		ft_rr(val, "rrb");
		ft_p(val, "pa");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
	}
	else if (z < y && y < x) // 1 2 3
	{
		ft_rr(val, "rrb");
		ft_rr(val, "rrb");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (z < y && y > x && x > z) // 1 3 2
	{
		ft_rr(val, "rrb");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (z > y && y < x && z > x) // 3 1 2
	{
		ft_rr(val, "rrb");
		ft_p(val, "pa");
		ft_rr(val, "rrb");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (z > y && y < x && z < x) // 2 1 3
	{
		ft_rr(val, "rrb");
		ft_rr(val, "rrb");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
		ft_s(val, "sb");
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (z < y && y > x && z > x) // 2 3 1
	{
		ft_rr(val, "rrb");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
		ft_p(val, "pa");
		ft_rr(val, "rrb");
		ft_p(val, "pa");
	}
}
