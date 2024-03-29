/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:32:41 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/17 17:49:30 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

void	error_exit_all(t_stack **a, char **sent)
{
	free_stack(a);
	freesplit(sent);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_exit(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_algo(t_stack	**a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

bool	onlydigit(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

bool	same_value(t_stack **a)
{
	t_stack	*curr;
	t_stack	*cmp;

	if (!(*a))
		return (0);
	curr = *a;
	while (curr->next)
	{
		cmp = curr->next;
		while (cmp)
		{
			if (cmp->nbr == curr->nbr)
				return (1);
			cmp = cmp->next;
		}
		curr = curr->next;
	}
	return (0);
}
