/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:32:36 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/13 19:39:29 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"
#include	<unistd.h>
#include	<stdlib.h>

void	ft_initialize(t_param *val)
{
	val->init_size = val->size_a;
	val->aux_size = val->size_a;
	val->size_b = 0;
	val->head_b = NULL;
	val->tail_b = NULL;
	val->aux_up = NULL;
	val->aux_down = NULL;
	val->chunk_size = NULL;
	val->chunk_size_b = NULL;
}

void	ft_final_free(t_param *val)
{
	ft_freelst(&val->aux_up);
	ft_freelst(&val->aux_down);
	ft_freelst(&val->head_a);
	ft_freelst(&val->head_b);
	ft_freelst(&val->head_b);
	if (val->chunk_size)
		ft_freelst(&val->chunk_size);
	if (val->chunk_size_b)
		ft_freelst(&val->chunk_size_b);
	ft_freelst(&val->pass_b);
	free(val);
	exit(1);
}

int	ft_err(int argc, char **argv, t_param	*val)
{
	if (argc == 2)
	{
		if (ft_nbr_and_order_str(argv, -1, 0))
			return (1);
		if (ft_check_double_str(argv, 0, 1))
			return (1);
		ft_chop(argv, val);
	}
	else
	{
		if (ft_nbr_and_double(argv, argc))
			return (1);
		if (ft_check_order(argv, argc))
		{
			exit (1);
		}
		ft_filling(argv, val, argc);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	*val;

	if (argc < 2 || !ft_strlen(argv[1]))
		return (0);
	val = malloc(sizeof(t_param));
	if (ft_err(argc, argv, val))
	{
		free(val);
		write(2, "Error\n", 6);
		return (0);
	}
	ft_initialize(val);
	if (val->size_a <= 3)
		ft_three_nbrs(val);
	if (val->size_a > 3 && val->size_a < 6)
		ft_five_nbrs(val);
	if (val->size_a > 5)
		ft_ultimate(val, val->head_a);
	if (val->head_a)
		ft_final_free(val);
	return (0);
}
