/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:23:37 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/10 08:10:29 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_ultimate(t_param *val)
{
	t_node	*aux;

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
	}
	if (val->head_a->content > val->head_a->next->content)
		ft_s(val, "sa");
	aux = val->chunk_size;
	while (aux->next != NULL)
		aux = aux->next;
	ft_delnode(&val->chunk_size, aux);
	ft_printlst(&val->chunk_size);
	ft_step_one(val, val->chunk_size);
}

//The next function iterates the list of chunks with a copy of it
void	ft_step_one(t_param *val, t_node *chunk)
{
	while (chunk != NULL && chunk->content > 0)
	{
		if (chunk->content >= 1 && chunk->content <= 3)
			ft_sort_three(val, chunk->content);
		else if (chunk->content >= 4 && chunk->content <= 6)
			ft_sort_six(val, val->head_b, val->aux_down, chunk->content);
		else if (chunk->content >= 7 && chunk->content <= 12)
			ft_sort_twelve(val, val->head_b, val->aux_down, chunk->content);
		else
			break ;
		/*
		else if (chunk->content >= 13 && chunk->content <= 18)
			ft_sort_eighteen();
		else if (chunk->content >= 19 && chunk->content <= 24)
			ft_sort_twentyfour();
		else if (chunk->content == 25)
			ft_sort_twentyfive();
		else if (chunk->content >= 26 && chunk->content <= 50)
			ft_sort_fifty();
			*/
		chunk->content = 0;
		chunk = chunk->next;
	}
	ft_printlst(&val->chunk_size);
	if (ft_sort(val->head_a))
			printf("\nOKKKKKKKKK\n");
	else
			printf("\nFATAAAAAAAAAAAAAAAL\n");
}






/*
		while (val->chunk_size->content > 6
			&& !ft_desort(val->head_b, val->chunk_size->content))
		{
			val->piv = ft_piv_b(val, val->aux_down, val->chunk_size->content);
			printf("\npivot b dentro: %d \n", val->piv);
			ft_passb(val, val->chunk_size, val->chunk_size->content, 0);
		}

	while (val->chunk_size != NULL)
	{
		if (val->chunk_size != NULL && val->chunk_size->content <= 3)
		{
			ft_less_than_three_b(val, val->chunk_size->content);
			val->chunk_size->content = 0;
			if (val->chunk_size->next != NULL)
				val->chunk_size = val->chunk_size->next;
		}
		else if (val->chunk_size != NULL && val->chunk_size->content >= 4
			&& val->chunk_size->content <= 6)
		{
			ft_less_six_b(val, val->head_b, val->aux_down, val->size_a + 3);
			val->chunk_size->content = 0;
			if (val->chunk_size->next != NULL)
				val->chunk_size = val->chunk_size->next;
		}
		else if (val->chunk_size != NULL && val->chunk_size->content >= 7
			&& val->chunk_size->content <= 50)
		{
			ft_step_two(val, val->chunk_size->content);
			val->chunk_size->content = 0;
			if (val->chunk_size->next != NULL)
				val->chunk_size = val->chunk_size->next;
		} 
	}


//	}

void	ft_step_two(t_param *val, int chunk_s)
{
	int	reference;

	reference = val->size_a;
	if (chunk_s <= 12)
	{
		val->chunk_size = 0;
	}
	else if (chunk_s > 12 && chunk_s <= 25)
	{
		ft_medium_chunk(val, val->aux_down, val->size_a + 12);
		if (chunk_s <= 18)
		{
			ft_less_six_a(val, val->aux_up, val->size_b + 4);
			ft_less_six_b(val, val->head_b, val->aux_down, val->size_a + 3);
		}
		if (chunk_s >= 19 && chunk_s <= 24)
		{
			ft_medium_chunk_2(val, val->aux_up, val->size_b + (24 - 18));
			val->chunk_size->content = val->size_b - chunk_s;
			ft_step_two(val, val->chunk_size->content);
			val->chunk_size->content = val->size_b;
		}
		if (chunk_s == 25)
		{
			printf("\nentraste \n");
			ft_medium_chunk_2(val, val->aux_up, val->size_b + (chunk_s - 18));
			ft_less_six_a(val, val->aux_up, val->size_b + 4);
			ft_medium_chunk_3(val, val->aux_up, val->size_b + (chunk_s - 25));
		}
	}
	else if (chunk_s > 25  && chunk_s <= 50)
	{
		ft_large_chunk(val, val->aux_down, val->size_a + 25);
		ft_large_chunk_2(val, val->aux_up, val->size_b + (50 - 31));
		ft_less_six_a(val, val->aux_up, val->size_b + 4);
		val->chunk_size->content = 19;
		ft_step_two(val, val->chunk_size->content);
		ft_p(val, "pa");
		val->chunk_size->content = 12;
		ft_step_two(val, val->chunk_size->content);
		val->chunk_size->content = val->size_b;
		ft_step_two(val, val->chunk_size->content);
	}
}
				*/
/*
void	ft_step_three(t_param *val, int chunk_s)
{

	else if (val->chunk_size->content > 50  && val->chunk_size->content <= 100)
	else if (val->chunk_size->content > 100  && val->chunk_size->content <= 200)
	else if (val->chunk_size->content > 200)


}
*/
