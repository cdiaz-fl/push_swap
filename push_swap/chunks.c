/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:08:13 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/10 10:28:54 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"push_swap.h"

t_chunk	*ft_new(t_chunk *chunks, int now)
{
	t_chunk	*tmp;

	tmp = chunks;
	tmp = malloc(sizeof(t_chunk));
	tmp->now = now;
	tmp->prev = -2147483648;
	tmp->next = NULL;
	return (tmp);
}

void	ft_printchunk(t_chunk	**head)
{
	t_chunk	*tmp;

	tmp = *head;
	printf("\n----------CHUNKS----------\n");
	while (tmp != NULL)
	{
		printf("[%d / ", tmp->prev);
		printf("%d] - ", tmp->now);
		tmp = tmp->next;
	}
}

void ft_freechunk(t_chunk **head)
{
	t_chunk	*tmp;
	t_chunk	*aux;

	aux = *head;
	while (aux != NULL)
	{
		tmp = aux->next;
		free(aux);
		aux = tmp;
	}
	*head = NULL;
}

void	ft_addbackchunk(t_chunk	**head, int now)
{
	t_chunk	*tmp;
	t_chunk	*new;

	tmp = *head;
	if (head)
	{
		new = malloc(sizeof(t_chunk));
		new->now = now;
		while (tmp != NULL)
		{
			if (tmp->next == NULL)
				break;
			tmp = tmp->next;
		}
		new->prev = tmp->now;
		tmp->next = new;
		new->next = NULL;
	}
}

int	ft_chunklen(t_chunk **head)
{
	t_chunk	*tmp;
	int			i;

	i = 1;
	tmp = *head;
	if (!tmp)
		return (0);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_chunk	*ft_chunksget(t_chunk **head, int n)
{
	int		i;
	t_chunk	*tmp;

	i = 1;
	tmp = *head;
	if (!tmp)
		return (NULL);
	while (i < n && tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

int	ft_chunk_count(t_node *b, t_chunk *chk)
{
	int count;

	count = 0;
	while (b != NULL)
	{
		if (b->content >= chk->prev && b->content < chk->now)
			count++;
		b = b->next;
	}
	return (count);
}
