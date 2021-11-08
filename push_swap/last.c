/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:13:30 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/06 13:53:00 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"
#include	"stdlib.h"

void	ft_last(t_param *val, t_node *tmp, int pas)
{
	if (tmp != NULL && tmp->content == 0)
		tmp = tmp->next;
	while (!ft_desort(val->head_b, val->size_b))
	{

		while (!ft_desort(val->head_b, tmp->content) && tmp->content > 1)
		{
			printf("\nchunk actual %d\n", tmp->content);
			ft_printlst(&val->chunk_size);
			val->piv = ft_piv_b(val, val->aux_down, tmp->content);
			printf("\npivot b dentro: %d \n", val->piv);
			ft_passb(val, tmp, tmp->content, 0);
			printf("\nantes %d\n", tmp->content);
			if (tmp->content <= 0 && tmp->next != NULL)
				tmp = tmp->next;
		}
		if (ft_desort(val->head_b, tmp->content) && tmp->next != NULL)
		{
			pas = tmp->content;
			while (pas && val->size_b > 1)
			{
				ft_p(val, "pa");
				pas--;
			}
			tmp->content = 0;
			if (tmp->next != NULL)
				tmp = tmp->next;
		}
		val->piv = ft_piv_b(val, val->aux_down, tmp->content);
		printf("\npivot b: %d \n", val->piv);

	}
	ft_cal_chk(val, val->head_a);
}

void	ft_cal_chk(t_param	*val, t_node *tmp)
{
	t_node	*last;
	int	i;
	int	b;

	i = -1;
	last = ft_new_node(tmp->content);
	while (tmp != NULL)
	{
		while (tmp != NULL)
		{
			i++;
			if (ft_m(last, tmp))
				break ;
			if (tmp->content > last->content)
				last->content = tmp->content;
			tmp = tmp->next;
		}
		last->content = tmp->content;
		if (tmp != NULL)
			tmp = tmp->next;
		if (i == 1)
			b++;
		else
		{
			if (b)
			{
				ft_addback(&val->chunk_size_b, b);
				b = 0;
			}
			ft_addback(&val->chunk_size_b, i);
		}
		i = 0;
	}
	ft_delnode(&val->chunk_size_b, val->chunk_size_b);
	if (val->chunk_size_b->content == 0)
		ft_delnode(&val->chunk_size_b, val->chunk_size_b);
	printf("La lista b: ");
	ft_printlst(&val->chunk_size_b);
	free (last);
}

void	ft_chkinversesorted(t_param *val, int quant)
{
	int	aux;

	aux = quant;
	while (--aux)
		ft_r(val, "rb");
	while (quant)
	{
		quant--;
		ft_p(val, "pa");
		if (quant == 0)
			return ;
		ft_rr(val, "rrb");
	}
}

void	ft_passb(t_param *val, t_node *t, int chunk_size, int count)
{
	val->chunks_count = 0;
	if (chunk_size % 2 == 0)
		chunk_size /= 2;
	else
		chunk_size = (t->content / 2) + 1;
	printf("chunky %d\n", t->content);
	printf("chunko %d\n", chunk_size);
	while (chunk_size < t->content && (!ft_desort(val->head_b, t->content) || count))
	{
			//ft_chkinversesorted(val, t->content);
		if (val->head_b->content >= val->piv)
		{
			ft_p(val, "pa");
			val->chunks_count++;
			t->content--;
		}
		else if (++count)
			ft_r(val, "rb");
	}
	while (count)
	{
		ft_rr(val, "rrb");
		count--;
	}
}

int	ft_piv_b(t_param *val, t_node *tmp, int chunks)
{
	int	i;
	int	x;

	i = 0;
	if (chunks == 0)
		return (0);
	while (val->size_a > 0 && ++i <= val->size_a)
		tmp = tmp->next;
	if (chunks % 2 == 0)	
		i = 0;
	else
		i = -1;
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
