/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:42:30 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/06 14:12:44 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"


void	ft_last_a(t_param *val, t_node *tmp, int pbs)
{
	if (tmp != NULL && tmp->content == 0)
		tmp = tmp->next;
	while (!ft_sortch(val->head_a, val->size_a))
	{
		while (!ft_sortch(val->head_a, tmp->content))
		{
			val->piv = ft_piv_a(val, val->aux_up, tmp->content);
			printf("chunk actual %d\n", tmp->content);
			printf("pivot a dentro: %d \n", val->piv);
			ft_passa(val, tmp, tmp->content, 0);
			if (tmp->content <= 0 && tmp->next != NULL)
				tmp = tmp->next;
		}
		if (ft_sortch(val->head_a, tmp->content))
		{
			pbs = tmp->content;
			while (pbs && val->size_a)
			{
				ft_p(val, "pb");
				pbs--;
			}
			tmp->content = 0;
			if (tmp->next != NULL)
				tmp = tmp->next;
		}
		val->piv = ft_piv_a(val, val->aux_up, tmp->content);
		printf("\npivot a: %d \n", val->piv);

	}
	ft_cal_chka(val, val->head_b);
}

void	ft_cal_chka(t_param	*val, t_node *tmp)
{
	int last;
	int	i;
	int	b;

	i = -1;
	last = tmp->content;
	while (tmp->next != NULL)
	{
		while (tmp->next != NULL)
		{
			i++;
			if (ft_bd(last, tmp))
				break ;
			if (tmp->content < last)
				last = tmp->content;
			tmp = tmp->next;
		}
		if (tmp->next != NULL)
		{
			tmp = tmp->next;
			last = tmp->content;
		}
		if (i == 1)
			b++;
		else
		{
			if (b)
			{
				ft_addback(&val->chunk_size, b);
				b = 0;
			}
			ft_addback(&val->chunk_size, i);
		}
		i = 0;
	}
	ft_delnode(&val->chunk_size, val->chunk_size);
	if (val->chunk_size->content == 0)
		ft_delnode(&val->chunk_size, val->chunk_size);
	printf("La lista a:    ");
	ft_printlst(&val->chunk_size);
}


void	ft_preva(t_param *val, t_node *t)
{
	if (t->content == 1)
	{
		ft_p(val, "pb");
		t->content--;
	}
	else if (t->content == 2
		&& val->head_a->content > val->head_a->next->content)
	{
		ft_s(val, "sa");
		if (val->size_a == 2)
			return ;
		ft_p(val, "pb");
		ft_p(val, "pb");
		t->content--;
	}
	else
	{
		ft_p(val, "pb");
		ft_p(val, "pb");
		t->content--;
	}
	t->content--;
	val->chunks_count++;
}

void	ft_passa(t_param *val, t_node *t, int chunk_size, int count)
{
	val->chunks_count = 0;
	if (chunk_size % 2 == 0 || t->content == 1)
		chunk_size /= 2;
	else
		chunk_size = (chunk_size / 2) + 1;
	printf("chunky %d\n", t->content);
	printf("chunko %d\n", chunk_size);
	while (chunk_size < t->content && (!ft_sortch(val->head_a, t->content) || count))
	{
		if (t->content <= 2)
			ft_preva(val, t);
		else if (val->head_a->content < val->piv)
		{
			ft_p(val, "pb");
			val->chunks_count++;
			t->content--;
		}
		else if (++count)
			ft_r(val, "ra");
		if (val->chunks_count == 0 && count == 0)
			return ;
	}
	while (count)
	{
		ft_rr(val, "rra");
		count--;
	}
}

int	ft_piv_a(t_param *val, t_node *tmp, int chunks)
{
	int	i;
	int	x;

	i = 0;

	if (chunks == 0)
		return (0);
	while (val->size_b > 0 && ++i <= val->size_b)
		tmp = tmp->next;
	if (chunks % 2 == 0)	
		i = 0;
	else
		i = -1;
		i = -1;
	printf("la i es         %d   ", i);
	printf("AUX:   ");
	ft_printlst(&tmp);
	while (++i <= (chunks / 2))
	{
		if (tmp != NULL)
		{
			x = tmp->content;
			tmp = tmp->next;
		}
	}
	return (x);
}
