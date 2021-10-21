/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:34:17 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/21 09:55:16 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

void	ft_three_nbrs(t_param *val)
{
	if (ft_b(val->head_a, val->head_a) && ft_m(val->tail_a, val->head_a)
			&& val->size_a == 2) 
		ft_s(val, "sa");
	else if (ft_b(val->head_a, val->head_a) && ft_m(val->tail_a, val->head_a))
	{
		ft_s(val, "sa");
		ft_rr(val, "rra");
	}
	else if (ft_b(val->head_a, val->head_a) && !ft_m(val->tail_a, val->head_a))
		ft_r(val, "ra");
	else if (ft_b(val->tail_a, val->head_a) && !ft_m(val->head_a, val->head_a))
		ft_s(val, "sa");
	else if (!ft_b(val->head_a, val->head_a) && ft_m(val->tail_a, val->head_a))
		ft_rr(val, "rra");
	else if (!ft_b(val->tail_a, val->head_a) && ft_m(val->head_a, val->head_a))
	{
		ft_s(val, "sa");
		ft_r(val, "ra");
	}
}

void	ft_five_nbrs(t_param *val)
{
	val->chunk_size = ft_new_node(val->size_a);
	val->chunk_size_b = ft_new_node(val->size_a);
	ft_p(val, "pb");
	ft_p(val, "pb");
	ft_three_nbrs(val);
	if (ft_sort(val->head_b))
	{
				ft_s(val, "sb");
	}
	if (val->head_a->content > val->head_b->content)
	{
		ft_p(val, "pa");
		ft_p(val, "pa");
		
	}
	else if (val->head_a->content > val->tail_b->content)
	{
		if (val->tail_a->content > val->head_b->content)
		{
			if (val->head_a->next->content > val->head_b->content)
			{
				ft_p(val, "pa");
				ft_s(val, "sa");
				ft_p(val, "pa");
				
			}	
			if (val->head_a->next->content < val->head_b->content
					&& val->tail_a->content > val->head_b->content)
			{
				ft_p(val, "pa");
				ft_rr(val, "rra");
				ft_s(val, "sa");
				ft_r(val, "ra");
				ft_r(val, "ra");
				ft_p(val, "pa");
				
			}	
		}
		else
		{
			ft_p(val, "pa");
			ft_r(val, "ra");
			ft_p(val, "pa");
		}
	}
	else
	{
		if (val->tail_a->content < val->tail_b->content)
		{
			ft_p(val, "pa");
			ft_p(val, "pa");
			ft_r(val, "ra");
			ft_r(val, "ra");
			
		}
		if (val->tail_a->content > val->head_b->content)
		{
			if (val->head_a->next->content > val->head_b->content)
			{
				ft_p(val, "pa");
				ft_s(val, "sa");
				ft_p(val, "pa");
				ft_s(val, "sa");
			}
			if (val->head_a->next->content < val->tail_b->content)
			{
				ft_p(val, "pa");
				ft_rr(val, "rra");
				ft_s(val, "sa");
				ft_p(val, "pa");
				ft_rr(val, "rra");
				ft_rr(val, "rra");
			}
			else
			{
				ft_p(val, "pa");
				ft_rr(val, "rra");
				ft_s(val, "sa");
				ft_rr(val, "rra");
				ft_rr(val, "rra");
				ft_p(val, "pa");
				ft_s(val, "sa");
			}
		}
		if (val->head_a->next->content > val->tail_b->content)
		{
				ft_p(val, "pa");
				ft_r(val, "ra");
				ft_p(val, "pa");
				ft_s(val, "sa");
		}
		if (val->head_a->next->content < val->tail_b->content)
		{
				ft_p(val, "pa");
				ft_r(val, "ra");
				ft_r(val, "ra");
				ft_p(val, "pa");
				ft_s(val, "sa");
				ft_rr(val, "rra");
		}
	}
}

int ft_sort(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int ft_desort(t_node *head, int n)
{
	int i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	while (i < n && tmp != NULL)
	{
		if (tmp->next != NULL && tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	ft_b(t_node *val, t_node *head)
{
	t_node	*tmp;

	tmp = head;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (val->content < tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_m(t_node *val, t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (val->content > tmp->content)
			return (0);
		tmp = tmp->next;
	}

	return (1);
}

int	ft_md(int val, t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->content > val)
			return (0);
		tmp = tmp->next;
	}

	return (1);
}

int	ft_bd(int val, t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->content < val)
			return (0);
		tmp = tmp->next;
	}

	return (1);
}
