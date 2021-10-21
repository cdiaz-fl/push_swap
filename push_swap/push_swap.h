/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:06:24 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/10/21 09:55:12 by cdiaz-fl         ###   ########.fr       */
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

typedef struct	s_chunk
{
	int						now;
	int						prev;
	struct s_chunk	*next;
}	t_chunk;

typedef struct	s_param
{
	int			init_size;
	int			aux_size;
	int			size_a;
	int			size_b;
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*head_b;
	t_node	*tail_b;
	t_node	*aux_up;
	t_node	*aux_down;
	t_node	*chunk_size;
	t_node	*chunk_size_b;
	int			piv;
	int			chunks_count;
	int			count_f_chk;
	int			movements;
}	t_param;



void	ft_print_stacks(t_param *val);



int		main(int argc, char **argv);
int		ft_err(int argc, char **argv, t_param	*val);
void	ft_chop(char **argv, t_param *val);
void	ft_free_nbrs(char **nbrs);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


t_node	*ft_new_node(int content);
void		ft_addfront(t_node **head, int content);
void		ft_addmiddle(t_node **head, int content, int position);
void		ft_addback(t_node	**head, int content);
void		ft_delnode(t_node **head, t_node *node);
void 		ft_freelst(t_node **head);
int			ft_lstlen(t_node **head);
t_node	*ft_lstend(t_node **head);
t_node	*ft_lstget(t_node **head, int n);
int	*ft_lst_d_get(t_node **head, int n);
void		ft_printlst(t_node	**head);



void ft_filling(char **argv, t_param *val, int argc);
int	ft_check_order(char **argv, int argc);
int	ft_nbr_and_double(char **argv, int argc);
void	ft_final_free(t_param *val);

void ft_chop(char **argv, t_param *val);
int	ft_nbr_and_order_str(char **argv);
int	ft_check_double_str(char **argv);
void	ft_free_nbrs(char **nbrs);
int	ft_is_nbr(char *str);

void	ft_s(t_param *val, char *c);
void	ft_r(t_param *val, char *c);
void	ft_rr(t_param *val, char *c);
void	ft_p(t_param *val, char *c);
void	ft_tail_size_write(t_param *val, int on, char *c);


void	ft_three_nbrs(t_param *val);
void	ft_five_nbrs(t_param *val);
int	ft_b(t_node *val, t_node *head);
int	ft_m(t_node *val, t_node *head);
int ft_sort(t_node *head);
int ft_desort(t_node *head, int n);

void	ft_final(t_param *val);
void	ft_aux_down(t_param *val, int help);
void	ft_aux_up(t_param *val, int help);
int	ft_get_aux(t_node *head, int n, t_param *val);
int	ft_chunk_aux(t_node *head, int n, t_param *val);
void	ft_sort_a(t_param *val);
void	ft_sort_b(t_param *val, int rb);
int	ft_bigger(t_node *head);

int	ft_deorder_size(t_param *val, t_node *head);
void	ft_sort_a_final(t_param *val, int ra);
int	ft_md(int val, t_node *head);
int	ft_pass_a(t_param *val, int ra, int on);
int	ft_take_piv(t_param *val, int max, t_node *head, int on);
void	ft_previous_a(t_param *val);


void	ft_sort_b_final(t_param *val, int ra);
int	ft_pass_b(t_param *val, int rb, int on);
int	ft_deorder_size_b(t_param *val, t_node *head);
void	ft_previous_b(t_param *val);
int	ft_bd(int val, t_node *head);

void	ft_second(t_param *val);
void	ft_almost(t_param *val);
#endif
