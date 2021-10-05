/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:06:24 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/09/29 16:21:34 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
#	include	<limits.h>

typedef struct	s_node
{
	int						content;
	struct s_node	*next;
}	t_node;

typedef struct	s_param
{
	int			size;
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*head_b;
	t_node	*tail_b;
}	t_param;


int		main(int argc, char **argv);
int		ft_err(int argc, char **argv, t_param	*val);
void	ft_chop(char **argv, t_param *val);
void	ft_free_nbrs(char **nbrs);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);


t_node	*ft_new_node(int content);
void		ft_addfront(t_node **head, int content);
void		ft_addmiddle(t_node **head, int content, int position);
void		ft_addback(t_node	**head, int content);
void		ft_delnode(t_node **head, t_node *node);
void 		ft_freelst(t_node **head);
int			ft_lstlen(t_node **head);
t_node	*ft_lstend(t_node **head);
void		ft_printlst(t_node	**head);


#endif
