/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_smaller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:30:38 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/03 15:30:26 by cdiaz-fl         ###   ########.fr       */
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

int	ft_bd(int val, t_node *head)
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
