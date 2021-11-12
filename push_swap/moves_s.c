/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:42:26 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/12 19:02:56 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"
#include	<unistd.h>	

void	ft_s(t_param *val, char *c)
{
	t_node	*tmp;
	t_node	*aux;

	ft_ss_rr_rrr(val, c);
	if (!ft_strncmp("sa", c, 2) || !ft_strncmp("ss", c, 2))
	{
		aux = val->head_a;
		tmp = val->head_a->next;
		val->head_a->next = tmp->next;
		tmp->next = val->head_a;
		val->head_a = tmp;
	}
	if (!ft_strncmp("sb", c, 2) || !ft_strncmp("ss", c, 2))
	{
		aux = val->head_b;
		tmp = val->head_b->next;
		val->head_b->next = tmp->next;
		tmp->next = val->head_b;
		val->head_b = tmp;
	}
	ft_tail_size_write(val, 0, c);
	//ft_print_stacks(val);
	if (ft_sort(val->head_a) && val->init_size == val->size_a)
		ft_final_free(val);
}

void	ft_r(t_param *val, char *c)
{
	t_node	*aux;

	ft_ss_rr_rrr(val, c);
	if (!ft_strncmp("ra", c, 2) || !ft_strncmp("rr", c, 2))
	{
		val->tail_a->next = val->head_a;
		aux = val->head_a->next;
		val->head_a->next = NULL;
		val->head_a = aux;
	}
	if (!ft_strncmp("rb", c, 2) || !ft_strncmp("rr", c, 2))
	{
		val->tail_b->next = val->head_b;
		aux = val->head_b->next;
		val->head_b->next = NULL;
		val->head_b = aux;
	}
	ft_tail_size_write(val, 0, c);
	//ft_print_stacks(val);
	if (ft_sort(val->head_a) && val->init_size == val->size_a)
	{
		ft_final_free(val);
		return ;
	}
}

void	ft_rr(t_param *val, char *c)
{
	t_node	*aux;

	ft_ss_rr_rrr(val, c);
	if (!ft_strncmp("rra", c, 3) || !ft_strncmp("rrr", c, 3))
	{
		aux = ft_lstget(&val->head_a, val->size_a - 1);
		val->tail_a->next = val->head_a;
		aux->next = NULL;
		val->head_a = val->tail_a;
	}
	if (!ft_strncmp("rrb", c, 3) || !ft_strncmp("rrr", c, 3))
	{
		aux = ft_lstget(&val->head_b, val->size_b - 1);
		val->tail_b->next = val->head_b;
		aux->next = NULL;
		val->head_b = val->tail_b;
	}
	ft_tail_size_write(val, 0, c);
	//ft_print_stacks(val);
	if (ft_sort(val->head_a) && val->init_size == val->size_a)
	{
		ft_final_free(val);
		return ;
	}
}

void	ft_p(t_param *val, char *c)
{
	t_node	*aux;

	if (!ft_strncmp("pb", c, 2))
	{
		aux = val->head_a->next;
		val->head_a->next = val->head_b;
		val->head_b = val->head_a;
		val->head_a = aux;
	}
	if (!ft_strncmp("pa", c, 2))
	{
		aux = val->head_b->next;
		val->head_b->next = val->head_a;
		val->head_a = val->head_b;
		val->head_b = aux;
	}
	ft_tail_size_write(val, 1, c);
	//ft_print_stacks(val);
	if (ft_sort(val->head_a) && val->init_size == val->size_a)
	{
		ft_final_free(val);
		return ;
	}
}

void	ft_tail_size_write(t_param *val, int on, char *c)
{
	int	i;

	static int x;

	if (on && !ft_strncmp("pa", c, 2))
	{
		val->size_b--;
		val->size_a++;
	}
	if (on && !ft_strncmp("pb", c, 2))
	{
		val->size_a--;
		val->size_b++;
	}
	val->tail_a = ft_lstend(&val->head_a);
	val->tail_b = ft_lstend(&val->head_b);
	i = ft_strlen(c);
		write(1, c, i);
		write(1, "\n", 1);
//	printf("%s\n", c);
	x++;
//	printf("%movements %d\n", x);
}
