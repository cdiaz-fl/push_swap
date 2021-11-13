/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:21:53 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/13 17:56:28 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_last_rotate(int min, t_node *a, int i, t_param *val)
{
	if (val->head_b == 0)
	{
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

void	ft_calculator_3(t_node *a, int max, t_param *val, int i)
{
	while (a != NULL && a->content != max)
		a = a->next;
	while (a != NULL && ++i)
		a = a->next;
	val->ra = (val->size_a - i) + 1;
	val->rra = i - 1;
}

void	ft_calculator_4(t_node *a_aux, t_param *val, int i)
{
	while (a_aux != NULL && ++i)
		a_aux = a_aux->next;
	val->ra = (val->size_a - i) + 1;
	val->rra = i - 1;
}

int	ft_send(t_param *val, int final_1, int final_2, int final_3)
{
	int	final_4;

	final_4 = val->rrb + val->ra + 1;
	if (final_1 <= final_2 && final_1 <= final_3 && final_1 <= final_4)
	{
		val->best = 'a';
		return (final_1);
	}
	else if (final_2 <= final_1 && final_2 <= final_3 && final_2 <= final_4)
	{
		val->best = 'b';
		return (final_2);
	}
	else if (final_3 <= final_2 && final_3 <= final_1 && final_3 <= final_4)
	{
		val->best = 'c';
		return (final_3);
	}
	else
	{
		val->best = 'd';
		return (final_4);
	}
}
