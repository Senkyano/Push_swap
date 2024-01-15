/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:09:45 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/15 15:27:57 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

int	ope_do(t_stack **a, t_stack **b, char *str, int	ok)
{
	if (same_cmd(str, "pb") && ok == 0)
		push_cmd(a, b);
	else if (same_cmd(str, "pa") && ok == 0)
		push_cmd(b, a);
	else if (same_cmd(str, "sa") && ok == 0)
		swap(a);
	else if (same_cmd(str, "sb") && ok == 0)
		swap(b);
	else if (same_cmd(str, "ss") && ok == 0)
		swap_check(a, b);
	else if (same_cmd(str, "ra") && ok == 0)
		rota(a);
	else if (same_cmd(str, "rb") && ok == 0)
		rota(b);
	else if (same_cmd(str, "rr") && ok == 0 && (*b) && (*b)->next)
		rota_check(a, b);
	else if (same_cmd(str, "rra") && ok == 0)
		rev_rota(a);
	else if (same_cmd(str, "rrb") && ok == 0)
		rev_rota(b);
	else if (same_cmd(str, "rrr") && ok == 0 && (*b) && (*b)->next)
		rev_rota_check(a, b);
	else
		return (1);
	return (0);
}

int	same_cmd(char *str, char *sec)
{
	int	i;
	
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != sec[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_trie(t_stack **a)
{
	t_stack *curr;

	curr = *a;
	while (curr && curr->next)
	{
		if (curr->next->nbr < curr->nbr)
			return (0);
		curr = curr->next;
	}
	return (1);
}