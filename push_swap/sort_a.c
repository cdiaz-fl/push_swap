/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:40:58 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/21 09:54:42 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

void	ft_second(t_param *val)
{
	int	i;

	ft_sort_a_final(val, 0);


	i = val->size_b;	

	if (val->size_b == 2 && val->head_b->content < val->head_b->next->content)
		ft_s(val, "sb");
	if (ft_desort(val->head_b, val->size_b) && ft_sort(val->head_a))
	{
		while (i > 0)
		{
			ft_p(val, "pa");
			i--;
		}
	}
}


void	ft_sort_a_final(t_param *val, int rb)
{
	t_node	*copy;

	copy = val->chunk_size;
	while (val->size_b > 2 && ft_deorder_size(val, val->head_b))
	{
		val->count_f_chk = 0;
		if (val->size_b > 2 && copy->content % 2 == 0)
			val->piv = ft_take_piv(val, copy->content / 2, val->head_b, 1);
		else if (val->size_b > 2)
			val->piv = ft_take_piv(val, copy->content / 2 + 1, val->head_b, 0);
		while (val->size_b > 2 && !ft_md(val->piv, val->head_b) && copy->content > 2)
		{
			if (val->head_b->content > val->piv)
				ft_pass_a(val, rb, 0);
			else if (++rb)
				ft_r(val, "rb");
		}
		ft_pass_a(val, rb, 1);
		rb = 0;
		if (copy->content <= 2 && val->size_b > 2)
			ft_previous_a(val);
		ft_addfront(&val->chunk_size_b, val->count_f_chk);
		copy->content -= val->count_f_chk;
		if (copy->content == 0)
			copy = copy->next;
	}
	copy->content = 0;
}

int	ft_pass_a(t_param *val, int rb, int on)
{
	if (!on)
	{
		ft_p(val, "pa");
		val->count_f_chk++;
	}
	while (rb && on)
	{
		ft_rr(val, "rrb");
		rb--;
	}
	return (rb);
}

int	ft_deorder_size(t_param *val, t_node *head)
{
	int i;
	int	j;
	int	on;
	t_node	*aux;

	aux = val->aux_up;
	if (head->content == val->head_a->content)
		i = (val->init_size - val->size_a) + 1;
	else
		i = (val->init_size - val->size_b) + 1;
	while (--i > 0)
		aux = aux->next;
	j = 1;
	on = 0;
	while (head != NULL)
	{
		if (aux->content != head-> content)
		{
			i = j;
			on = 1;
		}
		aux = aux->next;
		head = head->next;
		j++;
	}
	if (!on)
		i = 0;
	return (i);
}

void	ft_previous_a(t_param *val)
{
	if (val->head_b->content > val->head_b->next->content)
	{
		ft_p(val, "pa");
		val->count_f_chk++;
	}
	else if (val->size_b > 2) 
	{
		ft_s(val, "sb");
		ft_p(val, "pa");
		ft_p(val, "pa");
		val->count_f_chk += 2;
	}
}
