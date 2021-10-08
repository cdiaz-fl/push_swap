/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:49:14 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/08 20:28:50 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

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
	val->size_a = j;
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
			if (ft_atoi(nbrs[i]) == ft_atoi(nbrs[j]))
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

int	ft_is_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("+-0123456789", str[i]))
				return (0);
		if (i > 0 && (str[i] == '+' || str[i] == '-'))
			return (0);
		i++;
	}
	if ((str[0] == '+' || str[0] == '-') && i > 11)
		return (0);
	if (str[0] != '+' && i > 10)
		return (0);
	if (str[0] == '-' && i == 11 && str[10] == '9')
		return (0);
	if (str[0] == '+' && i == 11 && (str[10] == '8' || str[10] == '9'))
		return (0);
	if (str[0] != '+' && i == 10 && (str[9] == '8' || str[10] == '9'))
		return (0);
	return (1);
}

int	ft_nbr_and_order_str(char **argv)
{
	char **nbrs;
	int	j;

	nbrs = ft_split(argv[1], ' ');
	j = 0;
	while (nbrs[j])
	{
		if (!ft_is_nbr(nbrs[j]))
		{
			ft_free_nbrs(nbrs);
			return (1);
		}
		j++;
	}
	j--;
	while (j - 1 >= 0 && nbrs[j])
	{
		if (ft_atoi(nbrs[j - 1]) >= ft_atoi(nbrs[j]))
			break ;
		j--;
	}
	ft_free_nbrs(nbrs);
	if (j == 0)
		return (1);
	return (0);
}
