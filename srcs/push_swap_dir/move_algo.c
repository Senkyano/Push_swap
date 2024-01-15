/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:23:36 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/12 14:21:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

void	only_a(t_stack **from, t_stack **to)
{
	if ((*from)->pile == 'a')
	{
		if ((*from)->nbr > (*from)->next->nbr && (*to)->nbr < (*to)->next->nbr)
			swap_all(from, to);
		else if ((*from)->nbr > (*from)->next->nbr)
			swap_pile(from);
	}
	else if ((*from)->pile == 'b')
	{
		if ((*from)->next)
		{
			if ((*from)->nbr < (*from)->next->nbr
				&& (*to)->nbr > (*to)->next->nbr)
				swap_all(from, to);
			else if ((*from)->nbr < (*from)->next->nbr)
				swap_pile(from);
		}
		push_to(from, to);
		if ((*to)->nbr > (*to)->next->nbr)
			swap_pile(to);
	}
}

void	cuting_part(t_stack **from, t_stack **to, t_ref ref)
{
	int	i;
	int	midsup;

	i = 0;
	midsup = ref.ind_mid + ((ref.end_taff - ref.ind_mid) / 2);
	while (i++ < ref.non_taff)
	{
		if ((*from)->nbr >= ref.tab[ref.ind_mid])
		{
			push_to(from, to);
			if ((*to)->nbr < ref.tab[midsup]
				&& (*from)->nbr < ref.tab[ref.ind_mid] && i < ref.non_taff - 1)
			{
				rota_all(from, to);
				i++;
			}
			else if ((*to)->nbr < ref.tab[midsup])
				rota_pile(to);
		}
		else
			rota_pile(from);
	}
}

void	ecomove(t_stack **from, t_stack **to, t_ref	sec, t_ref thr)
{
	while (sec.non_taff-- > 0 && thr.non_taff-- > 0 && (*to)->next
		&& (*from)->next)
		rev_rota_all(from, to);
	while (sec.non_taff-- > 0 && (*to)->next)
		rev_rota_pile(to);
	while (thr.non_taff-- > 0 && (*from)->next)
		rev_rota_pile(from);
}

void	do_move(t_stack	**from, t_ref ref)
{
	while (ref.non_taff-- > 0)
		rev_rota_pile(from);
}
