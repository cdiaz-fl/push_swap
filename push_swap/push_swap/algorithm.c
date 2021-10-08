/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:34:17 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/08 19:49:23 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

void	ft_three_nbrs(t_param *val)
{
	if (ft_b(val->head_a, val->head_a) && ft_m(val->tail_a, val->head_a)
			&& val->size_a == 2) 
	{
		ft_s(val, "sa");
		ft_print_stacks(val);
	}

	else if (ft_b(val->head_a, val->head_a) && ft_m(val->tail_a, val->head_a))
	{
		ft_s(val, "sa");
		ft_print_stacks(val);
		ft_rr(val, "rra");
		ft_print_stacks(val);
	}
	else if (ft_b(val->head_a, val->head_a) && !ft_m(val->tail_a, val->head_a))
	{
		ft_r(val, "ra");
		ft_print_stacks(val);
	}
	else if (ft_b(val->tail_a, val->head_a) && !ft_m(val->head_a, val->head_a))
	{
		ft_s(val, "sa");
		ft_print_stacks(val);
	}
	
	else if (!ft_b(val->head_a, val->head_a) && ft_m(val->tail_a, val->head_a))
	{
		ft_rr(val, "rra");
		ft_print_stacks(val);
	}
	else if (!ft_b(val->tail_a, val->head_a) && ft_m(val->head_a, val->head_a))
	{
		ft_s(val, "sa");
		ft_print_stacks(val);
		ft_r(val, "ra");
		ft_print_stacks(val);
	}

}

void	ft_five_nbrs(t_param *val)
{
	ft_p(val, "pb");
	ft_print_stacks(val);
	ft_p(val, "pb");
	ft_print_stacks(val);
	ft_three_nbrs(val);
	if (ft_sort(val->head_b))
	{
				ft_s(val, "sb");
				ft_print_stacks(val);
	}
	if (val->head_a->content > val->head_b->content)
	{
		ft_p(val, "pa");
		ft_print_stacks(val);
		ft_p(val, "pa");
		ft_print_stacks(val);
	}
	else if (val->head_a->content > val->tail_b->content)
	{
		if (val->tail_a->content > val->head_b->content)
		{
			if (val->head_a->next->content > val->head_b->content)
			{
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_s(val, "sa");
				ft_print_stacks(val);
				ft_p(val, "pa");
				ft_print_stacks(val);
			}	
			if (val->head_a->next->content < val->head_b->content
					&& val->tail_a->content > val->head_b->content)
			{
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_rr(val, "rra");
				ft_print_stacks(val);
				ft_s(val, "sa");
				ft_print_stacks(val);
				ft_r(val, "ra");
				ft_print_stacks(val);
				ft_r(val, "ra");
				ft_print_stacks(val);
				ft_p(val, "pa");
				ft_print_stacks(val);
			}	
		}
		else
		{
			ft_p(val, "pa");
			ft_print_stacks(val);
			ft_r(val, "ra");
			ft_print_stacks(val);
			ft_p(val, "pa");
			ft_print_stacks(val);
		}
	}
	else
	{
		if (val->tail_a->content < val->tail_b->content)
		{
			ft_p(val, "pa");
			ft_print_stacks(val);
			ft_p(val, "pa");
			ft_print_stacks(val);
			ft_r(val, "ra");
			ft_print_stacks(val);
			ft_r(val, "ra");
			ft_print_stacks(val);
		}
		if (val->tail_a->content > val->head_b->content)
		{
			if (val->head_a->next->content > val->head_b->content)
			{
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_s(val, "sa");
				ft_print_stacks(val);
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_s(val, "sa");
				ft_print_stacks(val);
			}
			if (val->head_a->next->content < val->tail_b->content)
			{
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_rr(val, "rra");
				ft_print_stacks(val);
				ft_s(val, "sa");
				ft_print_stacks(val);
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_rr(val, "rra");
				ft_print_stacks(val);
				ft_rr(val, "rra");
				ft_print_stacks(val);
			}
			else
			{
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_rr(val, "rra");
				ft_print_stacks(val);
				ft_s(val, "sa");
				ft_print_stacks(val);
				ft_rr(val, "rra");
				ft_print_stacks(val);
				ft_rr(val, "rra");
				ft_print_stacks(val);
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_s(val, "sa");
				ft_print_stacks(val);
			}
		}
		if (val->head_a->next->content > val->tail_b->content)
		{
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_r(val, "ra");
				ft_print_stacks(val);
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_s(val, "sa");
				ft_print_stacks(val);
		}
		if (val->head_a->next->content < val->tail_b->content)
		{
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_r(val, "ra");
				ft_print_stacks(val);
				ft_r(val, "ra");
				ft_print_stacks(val);
				ft_p(val, "pa");
				ft_print_stacks(val);
				ft_s(val, "sa");
				ft_print_stacks(val);
				ft_rr(val, "rra");
				ft_print_stacks(val);
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
