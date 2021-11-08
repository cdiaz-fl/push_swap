/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_chks_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:57:10 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/08 09:45:39 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_less_six_a(t_param *val, t_node *aux, int i)
{
	int	count;

	count = 1;
	while (--i)
		aux = aux->next;
	printf("\nless_six       %d    i%d  \n", aux->content, i);
	while (i <= 3)
	{
		if (val->head_a->content >= aux->content)
		{
			ft_r(val, "ra");
			count++;
		}
		else if (i++)
			ft_p(val, "pb");
	}
	while (--count)
		ft_rr(val, "rra");
	count = i;
	i = val->chunk_size->content;
	val->chunk_size->content = 3;
	printf("lo paso count =%d  content=%d\n", count, val->chunk_size->content);
	ft_less_than_three_a(val);
	while (--count)
	{
		printf("\npepepepe\n");
		ft_p(val, "pa");
	}
	val->chunk_size->content = count - 3;
	ft_less_than_three_a(val);
	val->chunk_size->content = 6;
}

void	ft_less_than_three_a(t_param *val)
{
	if (val->chunk_size_b->content == 1)
		return ;
	else if (val->chunk_size_b->content == 2
		&& val->head_a->content > val->head_a->next->content)
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
