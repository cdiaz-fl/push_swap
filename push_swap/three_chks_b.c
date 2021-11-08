/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_chks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:47:02 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/08 09:45:37 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_less_six_b(t_param *val, t_node *tmp, t_node *aux, int i)
{
	int	count;

	while (--i)
		aux = aux->next;
	while ((tmp->content < aux->content || tmp->next->content < aux->content
		|| tmp->next->next->content < aux->content) && ++i)
	{
		if (val->head_b->content < aux->content)
			ft_r(val, "rb");
		else if (val->head_b->next->content < aux->content)
		{
			ft_s(val, "sb");
			ft_r(val, "rb");
		}	
		else if (val->head_b->next->next->content < aux->content)
		{
			ft_r(val, "rb");
			ft_s(val, "sb");
			ft_rr(val, "rrb");
			ft_s(val, "sb");
			i--;
		}
		tmp = val->head_b;
	}
	count = i;
	i = val->chunk_size->content;
	val->chunk_size->content = 3;
	printf("lo paso count =%d  content=%d\n", count, val->chunk_size->content);
	ft_less_than_three_b(val, 0);
	while (--count > -1)
		ft_rr(val, "rrb");
	val->chunk_size->content = i - 3;
	ft_less_than_three_b(val, 1);
}

void	ft_less_than_three_b(t_param *val, int on)
{
	if (val->chunk_size->content == 1)
		ft_p(val, "pa");
	else if (val->chunk_size->content == 2
		&& val->head_b->content > val->head_b->next->content)
	{
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (val->chunk_size->content == 2)
	{
		ft_s(val, "sb");
		ft_p(val, "pa");
		ft_p(val, "pa");
	}
	else if (val->chunk_size->content == 0)
		return ;
	else
		ft_three_chk_1_b(val, val->head_b->content, val->head_b->next->content, 4);
	val->chunk_size->content = 0;
	if (on && val->chunk_size->next != NULL)
		val->chunk_size = val->chunk_size->next;
	ft_printlst(&val->chunk_size);
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
