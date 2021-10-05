/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:03:32 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/09/29 16:45:24 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"
#include	<stdio.h>

void	ft_free_nbrs(char **nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

void ft_chop(char **argv, t_param *val)
{
	char **nbrs;
	int	i;
	int	j;

	nbrs = ft_split(argv[1], ' ');
	j = 0;
	i = 0;
	while (nbrs[j])
		j++;	
	printf("i: %d\n", j);
	val->head_a = ft_new_node(ft_atoi(nbrs[i]));
	i++;
	while (i < j)
	{
		ft_addback(&val->head_a, ft_atoi(nbrs[i]));
		i++;
	}
	val->tail_a = ft_lstend(&val->head_a);
	ft_printlst(&val->head_a);
	ft_free_nbrs(nbrs);
}

int	ft_check_double_str(char **argv)
{
	char **nbrs;
	int	i;
	int	j;

	nbrs = ft_split(argv[1], ' ');
	i = 0;
	j = 1;
	if (!nbrs[j])
		return (1);
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (*nbrs[i] == *nbrs[j])
			{
				ft_free_nbrs(nbrs);
				return (1);
			}
			j++;
		}
		i++;
	}
	ft_free_nbrs(nbrs);
	return (0);
}

int	ft_check_order_str(char **argv)
{
	char **nbrs;
	int	**nbris;
	int	i;

	nbrs = ft_split(argv[1], ' ');
	i = 0;
	nbris = (int **)malloc(4 * sizeof(int *));
	if (!nbris)
		exit (1);
	while (nbris)
	{
		nbris[i] = (int *)malloc(1 * sizeof(int));
		nbris++;
	}
	//if (!ft_strchr(nbrs[i], "-+0123456789")
	//		return (1);
	//comprobar ints y letras
	while (nbris)
	{
		nbris[i][0] = ft_atoi(nbrs[i]);
		i++;
	}
	i = 1;
	while (nbris[i])
	{
		if (nbris[i - 1] > nbris[i])
			return (1);
		i++;
	}
	ft_free_nbrs(nbrs);
	return (0);
}

int	ft_err(int argc, char **argv, t_param	*val)
{
	if (argc == 2)
	{
		if (ft_check_double_str(argv))
			return (1);
		if (ft_check_order_str(argv))
			return (1);
		ft_chop(argv, val);
	}
	/*
	else
	{
		if (ft_check_double(argv))
			return (1);
		if (ft_check_order(argv))
			return (1);
		ft_fill(argv, val);
	}
	*/
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	*val;

	if (argc < 2)
		return	(0);
	val = malloc(sizeof(t_param));
	if (ft_err(argc, argv, val))
		return (0);
	ft_freelst(&val->head_a);
	free(val);
	return	(0);
}
