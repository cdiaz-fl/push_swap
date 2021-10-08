/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:03:32 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/08 20:28:47 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"
#include	<stdio.h>

void	ft_print_stacks(t_param *val)
{
	int	i;
	t_node	*tmp_a;
	t_node	*tmp_b;

	i = 1;
	tmp_a = val->head_a;
	if (val->size_b > 0)
		tmp_b = val->head_b;
	printf("\n\n///////////////////////////////////////////////////\n\n");
	printf("    \t       A       \t       B       \n");
	printf("    \t|-------------|\t|-------------|\n");
	while (tmp_a != NULL)
	{
		if (val->size_b == 0 || tmp_b == NULL)	
			printf("%d   \t| %11d |\t|             |\n", i, tmp_a->content);
		else
			printf("%d   \t| %11d |\t| %11d |\n", i, tmp_a->content, tmp_b->content);
		tmp_a = tmp_a->next;
		if (val->size_b > 0 && i <= val->size_b)
			tmp_b = tmp_b->next;
		i++;
	}
	printf("    \t|-------------|\t|-------------|\n");

	if(val->size_b == 0)	
	{
		printf("\n\nhead\t| %11d |\t|             |\n", val->head_a->content);
		printf("tail\t| %11d |\t|             |\n", val->tail_a->content);
		printf("size\t| %11d |\t|             |\n", val->size_a);
	}
	else
	{
		printf("\n\nhead\t| %11d |\t| %11d |\n", val->head_a->content, val->head_b->content);
		printf("tail\t| %11d |\t| %11d |\n", val->tail_a->content, val->tail_b->content);
		printf("size\t| %11d |\t| %11d |\n", val->size_a, val->size_b);
	}
	printf("\n\n///////////////////////////////////////////////////\n");
}


void	ft_final_free(t_param *val)
{
	ft_freelst(&val->head_a);
	if (val->size_b > 0)
		ft_freelst(&val->head_b);
	free(val);
	exit(1);
}

int	ft_err(int argc, char **argv, t_param	*val)
{
	if (argc == 2)
	{
		if (ft_check_double_str(argv))
			return (1);
		printf("no repite\n");
	
		if (ft_nbr_and_order_str(argv))
			return (1);
		printf("str orden correcto y es número\n");
		ft_chop(argv, val);
	}
	else
	{
		if (ft_check_order(argv, argc))
			return (1);
		printf("orden correcto\n");
		if (ft_nbr_and_double(argv, argc))
			return (1);
		printf("es número y no repite\n");
		ft_filling(argv, val, argc);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	*val;

	if (argc < 2)
		return	(0);
	val = malloc(sizeof(t_param));
	if (ft_err(argc, argv, val))
	{
		free(val);
		return (0);
	}
	val->init_size = val->size_a;
	val->size_b = 0;
	val->head_b = NULL;
	ft_print_stacks(val);


	if (val->size_a <= 3)
		ft_three_nbrs(val);

	if (val->size_a > 3 && val->size_a <= 5)
		ft_five_nbrs(val);
	if (val->size_a > 5)
		ft_large(val);
/*
	ft_p(val, "pb");
	ft_print_stacks(val);
	ft_p(val, "pb");
	ft_print_stacks(val);
	ft_p(val, "pb");
	ft_print_stacks(val);

	ft_s(val, "sa");
	ft_print_stacks(val);
	ft_s(val, "sb");
	ft_print_stacks(val);
	ft_s(val, "ss");
	ft_print_stacks(val);

	ft_r(val, "ra");
	ft_print_stacks(val);
	ft_r(val, "rb");
	ft_print_stacks(val);
	ft_r(val, "rr");
	ft_print_stacks(val);

	ft_rr(val, "rra");
	ft_print_stacks(val);
	ft_rr(val, "rrb");
	ft_print_stacks(val);
	ft_rr(val, "rrr");
	ft_print_stacks(val);
*/

	ft_final_free(val);
	return	(0);
}
