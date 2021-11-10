/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:50:17 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/10 08:52:40 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

//pasamos 6 de la B a la A
void	ft_sort_twelve(t_param *val, t_node *b, t_node *max, int chunk)
{
	int	i;
	int	count;

	i = 6 + val->size_a;
	count = 0;
	while (--i)
		max = max->next;
	while (i < 6)
	{
		if (b->content < max->content && b->next->content >= max->content)
		{
			ft_s(val, "sb");
			ft_p(val, "pa");
			i++;
		}
		else if (b->content < max->content)
		{
			ft_r(val, "rb");
			count++;
		}
		else if (b->content >= max->content && ++i)
			ft_p(val, "pa");
		b = val->head_b;
	}
	printf("\n Cuando pasamos a A count es %d    y     i es  %d \n", count, i);
	ft_sort_twelve_1(val, val->head_a, val->aux_up, count + 1);
	if ((chunk - 6) > 3)
		ft_sort_six(val, val->head_b, val->aux_down, chunk - 6);
	else
		ft_sort_three(val, chunk - 6);
}

//pasamos 3 de la A a la B y ordenamos los 6 que quedaron en la B
void	ft_sort_twelve_1(t_param *val, t_node *a, t_node *max, int bottom)
{
	int	i;
	int	count;

	while (--bottom)
		ft_rr(val, "rrb");
	i = 3 + val->size_b;
	count = 0;
	while (--i)
		max = max->next;
	while (i < 3)
	{
		if (a->content <= max->content)
		{
			ft_p(val, "pb");
			i++;
		}
		else 
		{
			ft_r(val, "ra");
			count++;
		}
		a = val->head_a;
	}
	ft_sort_twelve_2(val, 3, count, val->head_a);
}

//Ordenamos los 3 de la A teniendo en cuenta los que están abajo
void	ft_sort_twelve_2(t_param *val, int chunk, int bottom, t_node *a)
{
	t_node	*reference;
	int	x;
	int	y;

	reference = a;
	while (a->next->content != val->tail_a->content)
		a = a->next;
	y = a->content;
	a = reference;
	while (a->next->content != y)
		a = a->next;
	x = a->content;
	a = reference;
	printf("\n x es = %d \n", x);
	printf("\n y es = %d \n", y);
	printf("\n z es = %d \n", val->tail_a->content);
	printf("\n bottom es = %d \n", bottom);
	if (bottom == 0)
		ft_sort_three_a(val, chunk);
	else if (bottom == 1)
		ft_sort_twelve_21(val, chunk, val->tail_a->content, val->head_a);
	else if (bottom == 2)
		ft_sort_twelve_22(val, chunk, y, val->tail_a->content);
	else if (bottom == 3)
		ft_sort_twelve_23(val, x, y, val->tail_a->content);
	ft_sort_three(val, 3);
}

void	ft_sort_twelve_21(t_param *val, int chunk, int z, t_node *a)
{
	printf("\n entra21 \n");
	if (chunk == 1)
		ft_rr(val, "rra");
	else if (chunk == 2)
	{
		if (a->content > z)
			ft_rr(val, "rra");
		else
		{
			ft_rr(val, "rra");
			ft_s(val, "sa");
		}
	}
	else if (chunk == 3)
	{
		if (a->content > a->next->content && a->next->content > z) // 3 2 - 1
		{
			ft_s(val, "sa");
			ft_rr(val, "rra");
		}
		else if (a->content > z && a->content < a->next->content) // 2 3 - 1
			ft_rr(val, "rra");
		else if (a->content > z && z > a->next->content) // 3 1 - 2
		{
			ft_s(val, "sa");
			ft_rr(val, "rra");
			ft_s(val, "sa");
		}
		else if (a->content < z && z < a->next->content) // 1 3 - 2
		{
			ft_rr(val, "rra");
			ft_s(val, "sa");
		}
		else if (a->content < z && a->content > a->next->content) // 2 1 - 3
		{
			ft_rr(val, "rra");
			ft_s(val, "sa");
			ft_r(val, "ra");
			ft_s(val, "sa");
			ft_rr(val, "rra");
			ft_s(val, "sa");
		}
		else if (a->content < a->next->content && a->content < z) // 1 2 - 3
		{
			ft_rr(val, "rra");
			ft_s(val, "sa");
			ft_r(val, "ra");
			ft_s(val, "sa");
			ft_rr(val, "rra");

		}
	}
}


void	ft_sort_twelve_22(t_param *val, int chunk, int y, int z)
{
	t_node	*a;

	a = val->head_a;
	if (chunk == 2)
	{
		if (z > y)
		{
			ft_rr(val, "rra");
			ft_rr(val, "rra");
		}
		else
		{
			ft_rr(val, "rra");
			ft_rr(val, "rra");
			ft_s(val, "sa");
		}
	}
	else if (chunk == 3)
	{
		if (a->content > z && z > y) // 3 - 2 1
		{
			ft_rr(val, "rra");
			ft_rr(val, "rra");
		}
		else if (a->content > z && z < y && a->content > y) // 3 - 1 2
		{
			ft_rr(val, "rra");
			ft_rr(val, "rra");
			ft_s(val, "sa");
		}
		else if (a->content > z && z < y && y > a->content) // 2 - 1 3
		{
			ft_rr(val, "rra");
			ft_p(val, "pb");
			ft_rr(val, "rra");
			ft_s(val, "sa");
			ft_p(val, "pa");
		}
		else if (a->content < z && z > y && a->content > y) // 2 - 3 1
		{
			ft_rr(val, "rra");
			ft_s(val, "sa");
			ft_rr(val, "rra");
		}
		else if (a->content < z && z < y) // 1 - 2 3
		{
			ft_p(val, "pb");
			ft_rr(val, "rra");
			ft_rr(val, "rra");
			ft_s(val, "sa");
			ft_p(val, "pa");
		}
		else if (a->content < z && z > y && y > a->content) // 1 - 3 2
		{
			ft_p(val, "pb");
			ft_rr(val, "rra");
			ft_rr(val, "rra");
			ft_p(val, "pa");
		}
	}
}


void	ft_sort_twelve_23(t_param *val, int x, int y, int z)
{
	printf("\n entra23 \n");
	printf("\n x es = %d \n", x);
	printf("\n y es = %d \n", y);
	printf("\n z es = %d \n", z);
	if (z > y && y > x) // 3 2 1
	{
		ft_rr(val, "rra");
		ft_rr(val, "rra");
		ft_rr(val, "rra");
	}
	else if (z < y && y < x) // 1 2 3
	{
		ft_rr(val, "rra");
		ft_p(val, "pb");
		ft_rr(val, "rra");
		ft_rr(val, "rra");
		ft_s(val, "sa");
		ft_p(val, "pa");
	}
	else if (z < y && y > x && x > z) // 1 3 2
	{
		ft_rr(val, "rra");
		ft_rr(val, "rra");
		ft_s(val, "sa");
		ft_rr(val, "rra");
		ft_s(val, "sa");
	}
	else if (z > y && y < x && z > x) // 3 1 2
	{
		ft_rr(val, "rra");
		ft_rr(val, "rra");
		ft_rr(val, "rra");
		ft_s(val, "sa");
	}
	else if (z > y && y < x && z < x) // 2 1 3
	{
		ft_rr(val, "rra");
		ft_rr(val, "rra");
		ft_p(val, "pb");
		ft_rr(val, "rra");
		ft_s(val, "sa");
		ft_p(val, "pa");
	}
	else if (z < y && y > x && z > x) // 2 3 1
	{
		ft_rr(val, "rra");
		ft_rr(val, "rra");
		ft_s(val, "sa");
		ft_rr(val, "rra");
	}
}
//Ordenamos la B, el chunk de 3 y pasamos a A
void	ft_sort_twelve_3(t_param *val, int chunk, int bottom, t_node *a)
{
	t_node	*reference;
	int	x;
	int	y;

	reference = a;
	while (a->next->content != val->tail_a->content)
		a = a->next;
	y = a->content;
	a = reference;
	while (a->next->content != y)
		a = a->next;
	x = a->content;
	a = reference;
	printf("\n x es = %d \n", x);
	printf("\n y es = %d \n", y);
	printf("\n z es = %d \n", val->tail_a->content);
	bottom++;
	chunk++;
}

//Hacemos el método de pasar los que nos queden (menos de 6).
//void	ft_sort_twelve_4(t_param *val, int chunk, int bottom, t_node *a)
//{
	/*
	t_node	*reference;
	int	x;
	int	y;

	ft_sort_three(val, 3);
	b = val->head_b;
	reference = b;
	while (b->next->content != val->tail_b->content)
		b = b->next;
	y = b->content;
	b = reference;
	while (b->next->content != y)
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
		*/
//}
