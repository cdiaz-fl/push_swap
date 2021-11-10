/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:32:36 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/09 13:31:35 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"
#include	<unistd.h>
#include	<stdlib.h>

void	ft_print_stacks(t_param *val)
{
	int	i;
	t_node	*tmp_a;
	t_node	*tmp_b;

	i = 1;
	tmp_a = val->head_a;
	if (val->size_b > 0)
		tmp_b = val->head_b;
	else
		tmp_b = NULL;
	printf("\n\n///////////////////////////////////////////////////\n\n");
	printf("    \t       A       \t       B       \n");
	printf("    \t|-------------|\t|-------------|\n");
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (val->size_b == 0 || tmp_b == NULL)	
			printf("%d   \t| %11d |\t|             |\n", i, tmp_a->content);
		else if (val->size_a == 0 || tmp_a == NULL)	
			printf("%d   \t|             |\t| %11d |\n", i, tmp_b->content);
		else
			printf("%d   \t| %11d |\t| %11d |\n", i, tmp_a->content, tmp_b->content);
		if (val->size_a > 0 && i <= val->size_a)
			tmp_a = tmp_a->next;
		if (val->size_b > 0 && i <= val->size_b)
			tmp_b = tmp_b->next;
		i++;
	}
	printf("    \t|-------------|\t|-------------|\n");
	printf("chunks  ");
	if (val->chunk_size != NULL)
		ft_printlst(&val->chunk_size);
/*
	if(val->size_b == 0)	
	{
		printf("\n\nhead\t| %11d |\t|             |\n", val->head_a->content);
		printf("tail\t| %11d |\t|             |\n", val->tail_a->content);
		printf("size\t| %11d |\t|             |\n", val->size_a);
	}
	else if(val->size_b == 0)	
	{
		printf("\n\nhead\t|             |\t| %11d |\n", val->head_a->content);
		printf("tail\t|             |\t| %11d |\n", val->tail_a->content);
		printf("size\t|             |\t| %11d |\n", val->size_a);
	}
	else
	{
		printf("\n\nhead\t| %11d |\t| %11d |\n", val->head_a->content, val->head_b->content);
		printf("tail\t| %11d |\t| %11d |\n", val->tail_a->content, val->tail_b->content);
		printf("size\t| %11d |\t| %11d |\n", val->size_a, val->size_b);
	}
	*/
//	printf("\n\n///////////////////////////////////////////////////\n");
}

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
	if (val->chunk_size)
		ft_freelst(&val->chunk_size);
	if (val->chunk_size_b)
		ft_freelst(&val->chunk_size_b);
	free(val);
	exit(1);
}

int	ft_err(int argc, char **argv, t_param	*val)
{
	if (argc == 2)
	{
		if (ft_check_double_str(argv, 0, 1))
			return (1);
		if (ft_nbr_and_order_str(argv, -1, 0))
			return (1);
		ft_chop(argv, val);
	}
	else
	{
		
		if (ft_nbr_and_double(argv, argc))
			return (1);
		if (ft_check_order(argv, argc))
			exit (1);
			
		ft_filling(argv, val, argc);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	*val;

	if (argc < 2)
		return (0);
	val = malloc(sizeof(t_param));
	if (ft_err(argc, argv, val))
	{
		free(val);
		write(2, "Error\n", 6);
		return (0);
	}
	ft_initialize(val);
	ft_print_stacks(val);
	if (val->size_a <= 3)
		ft_three_nbrs(val);
	if (val->size_a > 3 && val->size_a < 6)
		ft_five_nbrs(val);
	if (val->size_a > 5)
		ft_ultimate(val);

//		ft_definitive(val);
	if (val->head_a)
		ft_final_free(val);
	return (0);
}
