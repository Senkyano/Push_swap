/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/12 14:16:36 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

void	sort_three(t_stack **a)
{
	t_stack	*sec;
	t_stack	*fst;

	fst = *a;
	sec = fst->next;
	if (fst->nbr > sec->nbr && fst->nbr < sec->next->nbr)
		swap_pile(a);
	else if (sec->nbr < fst->nbr)
		rota_pile(a);
	else if (sec->nbr > fst->nbr && sec->nbr > sec->next->nbr)
		rev_rota_pile(a);
	if (!trie_ok(a))
		sort_three(a);
	else
		return ;
}

void	dissection(t_stack **a, t_stack **b, t_ref ref)
{
	t_ref	sec;
	t_ref	fst;

	ref = first_half(ref);
	if (ref.non_taff == ref.size / 2 || ref.non_taff == ref.size / 2 - 1)
		before_mid(a, b, ref);
	else
		after_mid(a, b, ref);
	if (nbr_box(a) > 3)
		dissection(a, b, ref);
	if (nbr_box(a) == 3)
	{
		sort_three(a);
		reintegration(b, a, ref);
	}
	else if (ref.non_taff == ref.size / 2 - 1 || ref.non_taff == ref.size / 2)
	{
		fst = mid_sup(ref);
		reintegration(b, a, fst);
		sec = mid_low(ref);
		reintegration(b, a, sec);
	}
	else
		reintegration(b, a, ref);
}

void	reintegration(t_stack **from, t_stack **to, t_ref ref)
{
	int	i;

	i = 0;
	if (ref.non_taff <= 2)
	{
		while (i++ < ref.non_taff)
			only_a(from, to);
	}
	else if (ref.non_taff == 3)
		for_three(from, to, ref);
	else if (ref.non_taff > 2)
		all_for(from, to, ref);
}

void	for_three(t_stack **from, t_stack **to, t_ref ref)
{
	if ((*from)->pile == 'a')
	{
		if (three_good(from) == 0)
		{
			if ((*from)->nbr > (*from)->next->nbr)
				swap_pile(from);
			rota_pile(from);
			if ((*from)->nbr > (*from)->next->nbr)
				swap_pile(from);
			rev_rota_pile(from);
			if ((*from)->nbr > (*from)->next->nbr)
				swap_pile(from);
		}
	}
	else if ((*from)->pile == 'b')
	{
		while (ref.non_taff-- > 0)
			only_a(from, to);
	}
}

void	all_for(t_stack **from, t_stack **to, t_ref ref)
{
	t_ref	fst;
	t_ref	sec;
	t_ref	thr;

	fst = mid_supsup(ref);
	sec = mid_suplow(ref);
	thr = mid_lower(ref);
	cuting_part(from, to, ref);
	reintegration(to, from, fst);
	if ((*from)->pile == 'b')
	{
		ecomove(from, to, sec, thr);
		reintegration(to, from, sec);
		reintegration(from, to, thr);
	}
	else if ((*from)->pile == 'a')
	{
		do_move(to, sec);
		reintegration(to, from, sec);
		do_move(from, thr);
		reintegration(from, to, thr);
	}
}
