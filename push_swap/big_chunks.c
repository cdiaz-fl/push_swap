/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:28:17 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/09 07:11:07 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
/*
void	ft_little_chunk(t_param *val, t_node *aux, int i, int chunks)
{
	while (--i && aux->next != NULL)
		aux = aux->next;
	printf("\naux es       %d      \n", aux->content);
	while (chunks)
	{
		if (val->head_b->content < aux->content)
		{
			ft_r(val, "rb");
			i++;
		}
		else if (chunks--)
			ft_p(val, "pa");
	}
	while (--i > -1)
		ft_rr(val, "rrb");
	if ((val->chunk_size->content - 6) <= 3)
		ft_less_than_three_a(val);
	else
		ft_less_six_a(val, val->aux_up, val->size_b + 4);
	ft_less_six_b(val, val->head_b, val->aux_down, val->size_a + 3);
}

void	ft_medium_chunk(t_param *val, t_node *aux, int i)
{
	int	count;

	count = 12;
	while (--i && aux->next != NULL)
		aux = aux->next;
	printf("\naux grande es       %d   y content %d   \n", aux->content, count);
	val->chunks_count = count;
	while (count)
	{
		if (val->head_b->content < aux->content)
		{
			ft_r(val, "rb");
			i++;
		}
		else if (count--)
			ft_p(val, "pa");
	}
	while (--i > -1)
		ft_rr(val, "rrb");
}

void	ft_medium_chunk_2(t_param *val, t_node *aux, int i)
{
	int	count;

	count = 6;
	while (--i && aux->next != NULL)
		aux = aux->next;
	printf("\naux grande 2 es       %d    y count es %d  \n", aux->content, count);
	val->chunks_count = count;
	while (count)
	{
		if (val->head_a->content > aux->content)
		{
			ft_r(val, "ra");
			i++;
		}
		else if (count--)
			ft_p(val, "pb");
	}
	while (--i > -1)
		ft_rr(val, "rra");
	val->chunk_size->content = 6;
}


void	ft_medium_chunk_3(t_param *val, t_node *aux, int i)
{
	int	count;

	count = 1;
	while (--i && aux->next != NULL)
		aux = aux->next;
	printf("\naux grande 3 es       %d    y count es %d  \n", aux->content, count);
	val->chunks_count = count;
	while (count)
	{
		if (val->head_b->content < aux->content)
		{
			ft_r(val, "rb");
			i++;
		}
		else if (count--)
			ft_p(val, "pa");
	}
	while (--i > -1)
		ft_rr(val, "rrb");
	val->chunk_size->content = 6;
	ft_less_six_b(val, val->head_b, val->aux_down, val->size_a + 3);
	val->chunk_size->content = 12;
}

void	ft_large_chunk(t_param *val, t_node *aux, int i)
{
	int	count;

	count = 25;
	while (--i && aux->next != NULL)
		aux = aux->next;
	printf("\naux large es       %d  y count %d    \n", aux->content, count);
	val->chunks_count = count;
	while (count)
	{
		if (val->head_b->content < aux->content)
		{
			ft_r(val, "rb");
			i++;
		}
		else if (count--)
			ft_p(val, "pa");
	}
	while (--i > -1 && val->chunk_size->next != NULL)
		ft_rr(val, "rrb");
}

void	ft_large_chunk_2(t_param *val, t_node *aux, int i)
{
	int	count;

	count = (50 - 31);
	while (--i && aux->next != NULL)
		aux = aux->next;
	printf("\naux large 2 es       %d    y count es %d  \n", aux->content, count);
	val->chunks_count = count;
	while (count)
	{
		if (val->head_a->content > aux->content)
		{
			ft_r(val, "ra");
			i++;
		}
		else if (count--)
			ft_p(val, "pb");
	}
	while (--i > -1)
		ft_rr(val, "rra");
	val->chunk_size->content = 19;
}
*/
