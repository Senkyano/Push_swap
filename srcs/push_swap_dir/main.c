/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:28:22 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/18 16:33:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

// faire un tab de ref deja trie

int	main(int argc, const char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_ref	ref;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	build_in(&a, argv);
	if (same_value(&a))
		error_exit(&a);
	ref = order_tab(&a);
	ref.end_taff = 0;
	if (!trie_ok(&a))
	{
		if (nbr_box(&a) == 2)
			swap_pile(&a);
		else if (nbr_box(&a) == 3)
			sort_three(&a);
		else if (nbr_box(&a) > 3)
			dissection(&a, &b, ref);
	}
	free_all(&a, &b, ref);
	return (0);
}

void	free_all(t_stack **a, t_stack **b, t_ref ref)
{
	free_stack(a);
	free_stack(b);
	free(ref.tab);
}
