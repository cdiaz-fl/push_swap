/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:15:09 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/13 17:56:25 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_pass_to_b(t_param *val, t_node *a, t_node *nbrs)
{
	int	aux;
	int	i;

	while (val->size_a > ft_lstlen(&val->pass_b))
	{
		aux = 0;
		i = 1;
		while (i <= ft_lstlen(&val->pass_b))
		{
			if (val->head_a->content == nbrs->content)
				aux++;
			nbrs = nbrs->next;
			i++;
		}
		nbrs = val->pass_b;
		a = a->next;
		if (aux > 0)
			ft_r(val, "ra");
		else
			ft_p(val, "pb");
	}
}

void	ft_final_pass(t_param *val, t_node *b)
{
	t_node	*save;
	char	best;

	val->fin = 12000;
	while (b != NULL)
	{
		if (val->fin > ft_calculator_1(val, b, val->head_a, b->content))
		{
			val->fin = ft_calculator_1(val, b, val->head_a, b->content);
			save = b;
			best = val->best;
		}
		b = b->next;
	}
	ft_calculator_1(val, save, val->head_a, save->content);
	ft_pass_a(val);
}

int	ft_calculator_1(t_param *val, t_node *b, t_node *a, int nbr)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	while (b != NULL && ++i)
		b = b->next;
	val->rb = val->size_b - i;
	val->rrb = i;
	max = ft_bigger(a);
	min = ft_smaller(a);
	return (ft_calculator_2(val, nbr, max, min));
}

int	ft_calculator_2(t_param *val, int nbr, int max, int min)
{
	t_node	*a_aux;
	t_node	*a;
	int		i;

	i = 0;
	a = val->head_a;
	if (nbr < min)
	{
		while (a != NULL && a->content != min)
			a = a->next;
		while (a != NULL && ++i)
			a = a->next;
		val->ra = val->size_a - i;
		val->rra = i;
	}
	else if (nbr > max)
		ft_calculator_3(a, max, val, i);
	else
	{
		a_aux = ft_max_bellow(a, nbr);
		ft_calculator_4(a_aux, val, i);
	}
	return (ft_get_final(val, 0, 0, 0));
}

int	ft_get_final(t_param *val, int final_1, int final_2, int final_3)
{
	int	r;

	r = val->rb - val->ra;
	if (r < 0)
		r *= -1;
	final_1 = (val->rb + r) + 1;
	r = val->rrb + val->rra;
	if (r < 0)
		r *= -1;
	final_2 = (val->rrb + r) + 1;
	final_3 = val->rb + val->rra + 1;
	return (ft_send(val, final_1, final_2, final_3));
}
