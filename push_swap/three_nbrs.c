/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:22:35 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/06 10:46:18 by cdiaz-fl         ###   ########.fr       */
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

int	ft_sort(t_node *head)
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

int	ft_desort(t_node *head, int n)
{
	int		i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	if (n == 1)
		return (1);
	while (i < n && tmp != NULL)
	{
		if (tmp->next != NULL && tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	ft_sortch(t_node *head, int n)
{
	int		i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	ft_printlst(&head);
//	printf("\n n == %d\n", n);
//	printf("\n cabeza == %d\n", tmp->content);
	if (n == 0)
		return (1);
	if (n <= 1)
		return (0);
	while (i < n && tmp != NULL)
	{
		if (tmp->next != NULL && tmp->content > tmp->next->content)
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
