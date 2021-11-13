/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:36:25 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/13 19:26:00 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"
#include	<stdlib.h>

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

void	ft_chop(char **argv, t_param *val)
{
	char	**nbrs;
	int		i;
	int		j;

	nbrs = ft_split(argv[1], ' ');
	j = 0;
	i = 0;
	while (nbrs[j])
		j++;
	val->size_a = j;
	val->head_a = ft_new_node(ft_atoi(nbrs[i]));
	i++;
	while (i < j)
	{
		ft_addback(&val->head_a, ft_atoi(nbrs[i]));
		i++;
	}
	val->tail_a = ft_lstend(&val->head_a);
	ft_free_nbrs(nbrs);
}

int	ft_check_double_str(char **argv, int i, int j)
{
	char	**nbrs;

	nbrs = ft_split(argv[1], ' ');
	if (ft_real_atoi(nbrs[i]) > 2147483647
		|| ft_real_atoi(nbrs[i]) < -2147483648)
		return (1);
	if (!nbrs[j])
		exit (1);
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
	if (i > 11)
		return (0);
	if ((str[0] != '-' && str[0] != '+') && i > 10)
		return (0);
	if (ft_real_atoi(str) > 2147483647)
		return (0);
	if (ft_real_atoi(str) < -2147483648)
		return (0);
	return (1);
}

int	ft_nbr_and_order_str(char **argv, int j, int on)
{
	char	**nbrs;

	nbrs = ft_split(argv[1], ' ');
	while (nbrs[++j])
	{
		if (!ft_is_nbr(nbrs[j]))
		{
			ft_free_nbrs(nbrs);
			return (1);
		}
	}
	j--;
	while (j - 1 >= 0 && nbrs[j] && on == 0)
	{
		if (ft_atoi(nbrs[j - 1]) >= ft_atoi(nbrs[j]))
			on = 1;
		j--;
	}
	ft_free_nbrs(nbrs);
	if (on == 0)
		exit (1);
	return (0);
}
