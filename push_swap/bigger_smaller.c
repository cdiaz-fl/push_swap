/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_smaller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:30:38 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/12 14:36:32 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

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

void	ft_five_second_last(t_param *val)
{
	ft_p(val, "pa");
	ft_rr(val, "rra");
	ft_s(val, "sa");
	ft_rr(val, "rra");
	ft_rr(val, "rra");
	ft_p(val, "pa");
	ft_s(val, "sa");
}

int	ft_bigger(t_node *head)
{
	int	max;

	max = head->content;
	while (head != NULL)
	{
		if (head->content > max)
			max = head->content;
		head = head->next;
	}
	return (max);
}

int	ft_smaller(t_node *head)
{
	int	min;

	min = head->content;
	while (head != NULL)
	{
		if (head->content < min)
			min = head->content;
		head = head->next;
	}
	return (min);
}

t_node	*ft_max_bellow(t_node *head, int nbr)
{
	int	last;
	t_node	*bellow;

	last = -2147483648;
	while (head != NULL)
	{
		if (head->content < nbr && head->content > last)
		{
			bellow = head;
			last = head->content;
		}
		head = head->next;
	}
	return (bellow);
}
