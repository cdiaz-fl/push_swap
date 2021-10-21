/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:52:39 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/21 10:04:09 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"


int	ft_nbr_and_double(char **argv, int argc)
{
	int	j;
	int	i;
	int	k;

	k = 1;
	while (k < argc && argv[k])
	{
		j = 1;
		while (j < argc && argv[j])
		{
			i = 0;
			while (argv[j][i])
			{
				if (!ft_is_nbr(argv[j]))
					return (1);
				i++;
			}
			if (k != j && ft_atoi(argv[k]) == ft_atoi(argv[j]))
					return (1);
			j++;
		}
		k++;
	}
	return (0);
}

int	ft_check_order(char **argv, int argc)
{
	int	i;
	int	j;

	i = 2;
	j = 1;
	while (argv[i] && ft_atoi(argv[j]) < ft_atoi(argv[i]))
	{
		i++;
		j++;
	}
	if (i >= argc)
		return (1);
	return (0);
}

void ft_filling(char **argv, t_param *val, int argc)
{
	int	i;

	printf("i: %d\n", argc - 1);
	val->size_a = argc - 1;
	val->head_a = ft_new_node(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		ft_addback(&val->head_a, ft_atoi(argv[i]));
		i++;
	}
	val->tail_a = ft_lstend(&val->head_a);
	ft_printlst(&val->head_a);
}
