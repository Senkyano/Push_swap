/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaplib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:28:34 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/15 15:31:10 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPLIB_H
# define SWAPLIB_H

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ************************************************************************** */
// STACK
typedef struct s_stack
{
	int	nbr;
	char	pile;
	struct s_stack	*next;
}	t_stack;
// STACK
t_stack		*box(int value);
void		add_box(t_stack **a, t_stack *box);
void		build_in(t_stack **a, const char **argv);
void		free_stack(t_stack **a);
// OPERATIONS
void		action(char *str, char c);
void		push_to(t_stack **from, t_stack **to);
void		rev_rota(t_stack **box);
void		rev_rota_pile(t_stack **box);
void		rev_rota_all(t_stack **a, t_stack **b);
void		rota(t_stack **box);
void		rota_pile(t_stack **box);
void		rota_all(t_stack **a, t_stack **b);
void		swap_pile(t_stack **box);
void		swap(t_stack **box);
void		swap_all(t_stack **a, t_stack **b);
// CMD
void		swap_check(t_stack **a, t_stack **b);
void		push_cmd(t_stack **from, t_stack **to);
void		rev_rota_check(t_stack **a, t_stack **b);
void		rota_check(t_stack **a, t_stack **b);
int			ope_do(t_stack **a, t_stack **b, char *str, int ok);
int			same_cmd(char *str, char *sec);
int			check_trie(t_stack **a);
/* ************************************************************************** */

/* ************************************************************************** */
// DATA
typedef	struct s_data
{
	int		i;
	int		j;
	int		size;
	t_stack	*box;
	char	**sent;
}	t_data;
/* ************************************************************************** */

/* ************************************************************************** */
// REF
typedef	struct	s_ref
{
	int	*tab;
	int	size;
	int	half_taff;
	int non_taff;
	int	ind_mid;
	int	start_taff;
	int	end_taff;
}	t_ref;
// REFERENCE
t_ref		sort_ref(t_ref ref);
t_ref		tab_reference(t_stack **a);
t_stack		*mid_pos_ref(t_stack **a, t_ref ref);
t_ref		order_tab(t_stack **a);

// Calcule ref
t_ref		mid_sup(t_ref ref);
t_ref		mid_low(t_ref ref);
t_ref		mid_lower(t_ref ref);
t_ref		mid_supsup(t_ref ref);
t_ref		mid_suplow(t_ref ref);

/* ************************************************************************** */

// ERROR
void		error_exit(t_stack **a);
void		error_algo(t_stack	**a, t_stack **b);
bool		same_value(t_stack **a);
bool		onlydigit(char *str);
void		free_all(t_stack **a, t_stack **b, t_ref ref);
void		error_exit_all(t_stack **a, char **sent);

// SPLIT
int			count_words(const char *str);
char		*words(const char *str);
void		freesplit(char **sent);
char		**ft_split(const char *str, t_stack **a);

// UTILS
int			ft_atoi(char *str, t_stack **a, char **sent);
void		print_stack(t_stack **a);
bool		trie_ok(t_stack **a);
int			nbr_box(t_stack **a);
int			min_half(t_stack **a, int half);
int			three_good(t_stack **pile);
// ALGO
void		sort_three(t_stack **a);
t_stack		*last_box(t_stack **b);
t_ref		first_half(t_ref ref);
int			rest_taff(t_ref ref, int ind);
void		dissection(t_stack **a, t_stack **b, t_ref ref);
void		reintegration(t_stack **from, t_stack **to, t_ref ref);
void		all_for(t_stack **from, t_stack **to, t_ref ref);

// SEP CHUNK
void		after_mid(t_stack **a, t_stack **b, t_ref ref);
void		before_mid(t_stack **a, t_stack **b, t_ref ref);
void		chunk_diss_bis(t_stack **a, t_stack **b, t_ref ref);
void		cuting_part(t_stack **from, t_stack **to, t_ref ref);
int			chunk_diss(t_stack **a, t_stack **b, t_ref ref, int rev);

// MOVE_algo
void		for_three(t_stack **from, t_stack **to, t_ref ref);
void		only_a(t_stack **from, t_stack **to);
void		ecomove(t_stack **from, t_stack **to, t_ref sec, t_ref thr);
void		do_move(t_stack	**from, t_ref ref);

// CHECKER

char		*ft_join(char *s1, char *s2);
size_t		ft_strlen(const char *s);
char		*get_next_line(int fd);
char		*ft_aftline(char *curr);
char		*ft_line(char *curr);
int			ft_srch(char *src, char c);
char		*ft_readfile(int fd, char *rest);




#endif