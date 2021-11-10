/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:19:08 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/10 07:57:32 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>


# include	<stdio.h>



typedef struct s_node
{
	int				content;
	struct s_node	*next;
}	t_node;

typedef struct s_param
{
	int		init_size;
	int		aux_size;
	int		size_a;
	int		size_b;
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*head_b;
	t_node	*tail_b;
	t_node	*aux_up;
	t_node	*aux_down;
	t_node	*chunk_size;
	t_node	*chunk_size_b;
	int		piv;
	int		chunks_count;
	int		count_f_chk;
}	t_param;

void	ft_print_stacks(t_param *val);



void		ft_initialize(t_param *val);
void		ft_final_free(t_param *val);
int			ft_err(int argc, char **argv, t_param	*val);
int			main(int argc, char **argv);
void		ft_five_nbrs(t_param *val);
void		ft_five_first(t_param *val);
void		ft_five_second(t_param *val);
void		ft_five_third(t_param *val);
void		ft_five_four(t_param *val);
void		ft_aux_down(t_param *val, int help, t_node *tmp);
void		ft_aux_up(t_param *val, int help);
int			ft_get_aux(t_node *head, int n, t_param *val);
int			ft_take_piv(t_param *val, int max, t_node *head, int on);
void		ft_five_second_last(t_param *val);
int			ft_b(t_node *val, t_node *head);
int			ft_m(t_node *val, t_node *head);
int			ft_bd(int val, t_node *head);
void		ft_filling(char **argv, t_param *val, int argc);
int			ft_check_order(char **argv, int argc);
int			ft_nbr_and_double(char **argv, int argc);
void		ft_chop(char **argv, t_param *val);
void		ft_free_nbrs(char **nbrs);
int			ft_check_double_str(char **argv, int i, int j);
int			ft_is_nbr(char *str);
int			ft_nbr_and_order_str(char **argv, int j, int on);
void		ft_final(t_param *val);
void		ft_first_final(t_param *val);
void		ft_sort_a(t_param *val);
int			ft_bigger(t_node *head);
int			ft_lstlen(t_node **head);
t_node		*ft_lstend(t_node **head);
t_node		*ft_lstget(t_node **head, int n);
int			*ft_lst_d_get(t_node **head, int n);
void		ft_addfront(t_node **head, int content);
void		ft_addmiddle(t_node **head, int content, int position);
void		ft_addback(t_node	**head, int content);
void		ft_delnode(t_node **head, t_node *node);
void		ft_freelst(t_node **head);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
char		**ft_freepointer(char **p, size_t num_arrays);
char		**ft_fill(char **p, char *s, char c, size_t num_arrays);
size_t		ft_num_arrays(char *s, char c);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_s(t_param *val, char *c);
void		ft_r(t_param *val, char *c);
void		ft_rr(t_param *val, char *c);
void		ft_p(t_param *val, char *c);
void		ft_tail_size_write(t_param *val, int on, char *c);
void		ft_second(t_param *val);
void		ft_sort_a_final(t_param *val, int rb, t_node *copy);
int			ft_pass_a(t_param *val, int ra, int on);
int			ft_deorder_size(t_param *val, t_node *head);
void		ft_previous_a(t_param *val);
void		ft_almost(t_param *val);
void		ft_previous_b(t_param *val);
void		ft_sort_b_final(t_param *val, int ra, t_node *copy);
int			ft_pass_b(t_param *val, int rb, int on);
void		ft_ss_rr_rrr(t_param *val, char *c);
void		ft_three_nbrs(t_param *val);
int			ft_sort(t_node *head);
int			ft_desort(t_node *head, int n);
t_node		*ft_new_node(int content);
void		ft_sort_b(t_param *val, int rb);
int			ft_md(int val, t_node *head);
void		ft_take_it(t_param *val, t_node *copy);
long		ft_real_atoi(const char *nptr);











void	ft_definitive(t_param *val);
int	ft_piv(t_param *val, t_node *tmp);
void	ft_pass(t_param *val, int ref);
int	ft_best(t_param *val, int up, int down, t_node *tmp);
void	ft_take(t_param *val, char c);



void	ft_last(t_param *val, t_node *tmp, int pas);
int	ft_piv_b(t_param *val, t_node *tmp, int chunks);
void	ft_passb(t_param *val, t_node *t, int chunk_size, int count);
void	ft_prev(t_param *val, t_node *t);
void	ft_cal_chk(t_param	*val, t_node *tmp);
void	ft_chkinversesorted(t_param *val, int quant);



void	ft_last_a(t_param *val, t_node *tmp, int pas);
void	ft_preva(t_param *val, t_node *t);
void	ft_passa(t_param *val, t_node *t, int chunk_size, int count);
int	ft_sortch(t_node *head, int n);
void	ft_cal_chka(t_param	*val, t_node *tmp);
int	ft_piv_a(t_param *val, t_node *tmp, int chunks);


//Martes 9 Noviembre
void	ft_ultimate(t_param *val);
void	ft_step_one(t_param *val, t_node *chunk_now);
void	ft_sort_three(t_param *val, int chunks);
void	ft_sort_three_a(t_param *val, int chunks);
void	ft_sort_six(t_param *val, t_node *b, t_node *max, int chunk);
void	ft_sort_six_1(t_param *val, int chunk, int bottom, t_node *b);
void	ft_sort_six_2(t_param *val, int chunk, int z, t_node *b);
void	ft_sort_six_3(t_param *val, int chunk, int y, int z);
void	ft_sort_six_4(t_param *val, int x, int y, int z);
void	ft_sort_twelve(t_param *val, t_node *b, t_node *max, int chunk);
void	ft_sort_twelve_1(t_param *val, t_node *a, t_node *max, int bottom);
void	ft_sort_twelve_2(t_param *val, int chunk, int bottom, t_node *a);
void	ft_sort_twelve_21(t_param *val, int chunk, int z, t_node *b);
void	ft_sort_twelve_22(t_param *val, int chunk, int y, int z);
void	ft_sort_twelve_23(t_param *val, int x, int y, int z);
void	ft_sort_twelve_3(t_param *val, int chunk, int bottom, t_node *a);




void	ft_less_than_three_a(t_param *val);
void	ft_three_chk_1_a(t_param *val, int x, int y);
void	ft_three_chk_1_b(t_param *val, int x, int y, int aux);
void	ft_three_chk_2_a(t_param *val, int x, int y, int z);
void	ft_three_chk_2_b(t_param *val, int x, int y, int z);
void	ft_less_six_a(t_param *val, t_node *aux, int i);











void	ft_step_two(t_param *val, int chunk_s);
void	ft_little_chunk(t_param *val, t_node *aux, int i, int chunks);
void	ft_medium_chunk(t_param *val, t_node *aux, int i);
void	ft_medium_chunk_2(t_param *val, t_node *aux, int i);
void	ft_medium_chunk_3(t_param *val, t_node *aux, int i);
void	ft_large_chunk(t_param *val, t_node *aux, int i);
void	ft_large_chunk_2(t_param *val, t_node *aux, int i);

void	ft_printlst(t_node	**head);











#endif