/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:15:09 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/12 18:58:46 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

//Mejoras: calcular cuál es más fácil de pasar y mirar tb la cola

void	ft_pass_to_b(t_param *val, t_node *a, t_node *nbrs)
{
	int	aux;
	int	i;

	ft_printlst(&a);	
	ft_printlst(&nbrs);	
	while(val->size_a > ft_lstlen(&val->pass_b))
	{
		aux = 0;
		i = 1;
		while(i <= ft_lstlen(&val->pass_b))
		{
			if (val->head_a->content == nbrs->content)
				aux++;
			nbrs = nbrs->next;
			i++;
		}
		//printf("aux es %d\n", aux);
		nbrs = val->pass_b;
		a = a->next;
		if (aux > 0)
			ft_r(val, "ra");
		else
			ft_p(val, "pb");
	}
	//printf("%d", a->content);
}
//Mejora: Mirar si es óptimo girar las 2 stacks para pasar de B a A
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
	//printf("el que menos movimientos supone es %d la opción %c \n", save->content, val->best);
	ft_pass_a(val);
}

int	ft_calculator_1(t_param *val, t_node *b, t_node *a, int nbr)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	//printf("\n del número %d \n", b->content);
	while (b != NULL && ++i)
		b = b->next;
	val->rb = val->size_b - i;
	//printf("rb es %d \n", val->size_b - i);
	val->rrb = i;
	//printf("rrb es %d \n", i);
	max = ft_bigger(a);
	min = ft_smaller(a);
	//printf("\n min es %d    y max es %d   \n", min, max);
	return (ft_calculator_2(val, nbr, max, min));

}

int	ft_calculator_2(t_param *val, int nbr, int max, int min)
{
	t_node	*a;
	t_node	*a_aux;
	int	i;

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
		//printf("ra es %d \n", val->ra);
		//printf("rra es %d \n", val->rra);
	}
	else if (nbr > max)
	{
		while (a != NULL && a->content != max)
			a = a->next;
		while (a != NULL && ++i)
			a = a->next;
		val->ra = (val->size_a - i) + 1;
		val->rra = i - 1;
		//printf("ra es %d \n", val->ra);
		//printf("rra es %d \n", val->rra);
	}
	else
	{
		a_aux = ft_max_bellow(a, nbr);
		//printf("a aux es %d \n", a_aux->content);
		while (a_aux != NULL && ++i)
			a_aux = a_aux->next;
		val->ra = (val->size_a - i) + 1;
		val->rra = i - 1;
		//printf("ra es %d \n", val->ra);
		//printf("rra es %d \n", val->rra);
	}
	return (ft_get_final(val, 0, 0, 0));
}

int	ft_get_final(t_param *val, int final_1, int final_2, int final_3)
{
	int	final_4;
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
	final_4 = val->rrb + val->ra + 1;
	//printf("final 1 es %d   final 2 es %d   final 3 es %d   y final 4 es %d \n", final_1, final_2, final_3, final_4);
	//printf("------------------\n");
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

