/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/12 14:21:29 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

int	min_half(t_stack **a, int half)
{
	t_stack	*curr;

	curr = *a;
	while (curr)
	{
		if (curr->nbr < half)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	after_mid(t_stack **a, t_stack **b, t_ref ref)
{
	int	rev;

	rev = 0;
	while (min_half(a, ref.tab[ref.end_taff]) && nbr_box(a) > 3)
	{
		if ((*a)->nbr < ref.tab[ref.end_taff])
			rev = chunk_diss(a, b, ref, rev);
		else
			rota_pile(a);
	}
	while (rev-- > 0)
		rev_rota_pile(b);
}

void	before_mid(t_stack **a, t_stack **b, t_ref ref)
{
	while (min_half(a, ref.tab[ref.end_taff]))
	{
		if ((*a)->nbr < ref.tab[ref.end_taff])
			chunk_diss_bis(a, b, ref);
		else
			rota_pile(a);
	}
}

int	chunk_diss(t_stack **a, t_stack **b, t_ref ref, int rev)
{
	push_to(a, b);
	if ((*b)->nbr > ref.tab[ref.ind_mid])
	{
		if ((*b)->next)
			rota_pile(b);
		rev++;
	}
	return (rev);
}

void	chunk_diss_bis(t_stack **a, t_stack **b, t_ref ref)
{
	push_to(a, b);
	if ((*b)->nbr < ref.tab[ref.ind_mid])
	{
		if ((*b)->next)
			rota_pile(b);
	}
}
