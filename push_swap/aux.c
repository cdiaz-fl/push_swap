/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:25:00 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/27 18:54:44 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

void	ft_aux_up(t_param *val, int help)
{
	t_node	*tmp;
	int		x;

	x = 2147483647;
	tmp = val->head_a;
	while (tmp != NULL)
	{
		if (tmp->content < x)
			x = tmp->content;
		tmp = tmp->next;
	}
	val->aux_up = ft_new_node(x);
	while (ft_lstlen(&val->aux_up) < ft_lstlen(&val->head_a))
	{
		tmp = val->head_a;
		help = x;
		x = 2147483647;
		while (tmp != NULL)
		{
			if (tmp->content < x && tmp->content > help)
				x = tmp->content;
			tmp = tmp->next;
		}
		ft_addback(&val->aux_up, x);
	}
}

void	ft_aux_down(t_param *val, int help, t_node *tmp)
{
	int	x;

	x = -2147483648;
	while (tmp != NULL)
	{
		if (tmp->content > x)
			x = tmp->content;
		tmp = tmp->next;
	}
	val->aux_down = ft_new_node(x);
	while (ft_lstlen(&val->aux_down) < ft_lstlen(&val->head_a))
	{
		tmp = val->head_a;
		help = x;
		x = -2147483648;
		while (tmp != NULL)
		{
			if (tmp->content > x && tmp->content < help)
				x = tmp->content;
			tmp = tmp->next;
		}
		ft_addback(&val->aux_down, x);
	}
}

int	ft_get_aux(t_node *head, int n, t_param *val)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = ft_lstget(&head, val->size_b);
	n += val->size_b;
	while (i < n)
	{
		head = head->next;
		i++;
	}
	return (head->content);
}

int	ft_take_piv(t_param *val, int max, t_node *head, int on)
{
	t_node	*aux;
	int		i;

	if (head->content == val->head_a->content)
		aux = val->aux_up;
	else
		aux = val->aux_down;
	if (head->content == val->head_a->content)
		i = (val->size_b);
	else
		i = (val->size_a);
	while (i-- != 0)
		aux = aux->next;
	if (!on)
		i = 1;
	else
		i = 0;
	while (i < max)
	{
		aux = aux->next;
		i++;
	}
	return (aux->content);
}
