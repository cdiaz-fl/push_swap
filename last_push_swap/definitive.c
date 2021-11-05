/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:17:58 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/05 17:29:04 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"
#include	<stdlib.h>


void	ft_printlst(t_node	**head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d - ", tmp->content);
		tmp = tmp->next;
	}
}







void	ft_definitive(t_param *val)
{

	ft_aux_up(val, 0);
	ft_aux_down(val, 0, val->head_a);
	val->chunk_size = ft_new_node(val->size_a);
	val->chunk_size_b = ft_new_node(val->size_a);
	while (val->size_a > 2 && !ft_sort(val->head_a))
	{
		val->piv = ft_piv(val, val->aux_up);
		printf("\npivot: %d \n", val->piv);
		ft_pass(val, val->size_a);
		ft_addfront(&val->chunk_size, val->chunks_count);
		ft_printlst(&val->chunk_size);
	}
	if (val->head_a->content > val->head_a->next->content)
		ft_s(val, "sa");

	while (!ft_sort(val->head_a) || !ft_desort(val->head_b, val->size_b))
	{

		ft_last(val, val->chunk_size, 0);
		free(val->chunk_size);
		val->chunk_size = ft_new_node(val->init_size);
		ft_last_a(val, val->chunk_size_b, 0);
		free(val->chunk_size_b);
		val->chunk_size_b = ft_new_node(val->init_size);
	}
	while (val->size_b > 0)
		ft_p(val, "pa");
}

void	ft_take(t_param *val, char c)
{
	val->chunks_count--;
	if (c == 'u')
	{
		while (val->head_a->content >= val->piv && !ft_sort(val->head_a))
			ft_r(val, "ra");
		if (ft_sort(val->head_a) || val->head_a->content < val->piv)
			return ;
		ft_r(val, "ra");
		if (ft_sort(val->head_a) || val->head_a->content < val->piv)
			return ;
		ft_p(val, "pb");
	}
	else
	{
		while (val->tail_a->content >= val->piv && !ft_sort(val->head_a))
			ft_rr(val, "rra");
		if (ft_sort(val->head_a))
			return ;
		ft_rr(val, "rra");
		if (ft_sort(val->head_a))
			return ;
		ft_p(val, "pb");
	}
	val->chunks_count++;
}

int	ft_best(t_param *val, int up, int down, t_node *tmp)
{
	int	i;

	i = 0;
	while (i < down)
	{
		if (tmp->content < val->piv)
		{
			up = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	i++;
	while (i < val->size_a)
	{
		if (tmp->content < val->piv)
			down = ((i - val->size_a) * -1) + 1;
		tmp = tmp->next;
		i++;
	}
	if (up == 0)
		up = val->size_a;
	printf("\n up %d\n", up);
	printf("\n down %d\n", down);
	if (down < up)
		return (0);
	else
		return (1);

}

void	ft_pass(t_param *val, int ref)
{
	val->chunks_count = 0;
	ref /= 2;
	while (val->chunks_count < ref && !ft_sort(val->head_a))
	{
		if (val->head_a->content < val->piv)
			ft_p(val, "pb");
		else if (val->tail_a->content < val->piv)
		{
			ft_rr(val, "rra");
			ft_p(val, "pb");
		}
		else
		{
			if (ft_best(val, 1, ref, val->head_a))
				ft_take(val, 'u');
			else
				ft_take(val, 'd');
		}
		val->chunks_count++;
	}
}

int	ft_piv(t_param *val, t_node *tmp)
{
	int	i;
	int	x;
	int	ref;

	if (val->size_a % 2 == 0)
		ref = val->size_a / 2;
	else 
		ref = (val->size_a / 2) + 1;
	i = 1;
	while (val->size_b > 0 && i <= val->size_b)
	{
		tmp = tmp->next;
		i++;
	}
	if (val->size_a % 2 == 0)
		i = 0;
	else 
		i = 1;
	while (i <= ref)
	{
			x = tmp->content;
			tmp = tmp->next;
			i++;
	}
	return (x);
}

