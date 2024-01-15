/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:46:30 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/12 14:21:41 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

t_stack	*last_box(t_stack **b)
{
	t_stack	*curr;

	curr = *b;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

bool	num_have(int *ref, int hv, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ref[i] == hv)
			return (0);
		i++;
	}
	return (1);
}

t_ref	order_tab(t_stack **a)
{
	t_stack	*src;
	t_ref	ref;
	int		i;
	int		tmp;

	i = 0;
	ref.size = nbr_box(a);
	ref.tab = malloc(sizeof(int) * ref.size);
	if (!ref.tab)
		error_exit(a);
	while (i < ref.size)
	{
		tmp = INT_MAX;
		src = *a;
		while (src)
		{
			if (num_have(ref.tab, src->nbr, i) && tmp > src->nbr)
				tmp = src->nbr;
			src = src->next;
		}
		ref.tab[i] = tmp;
		i++;
	}
	return (ref);
}

t_ref	first_half(t_ref ref)
{
	ref.non_taff = rest_taff(ref, ref.end_taff) / 2;
	ref.half_taff = ref.non_taff / 2;
	if (ref.non_taff == ref.size / 2)
	{
		ref.start_taff = ref.end_taff;
		ref.ind_mid = ref.half_taff;
		ref.end_taff = ref.non_taff;
	}
	else
	{
		ref.start_taff = ref.end_taff;
		ref.ind_mid = ref.end_taff + ref.half_taff;
		ref.end_taff = ref.end_taff + ref.non_taff;
	}
	return (ref);
}

int	rest_taff(t_ref ref, int ind)
{
	int	i;

	i = 0;
	while (ind++ < ref.size - 1)
		i++;
	return (i);
}
