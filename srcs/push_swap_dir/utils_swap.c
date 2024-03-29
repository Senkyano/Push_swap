/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:01:40 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/18 16:48:36 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

int	ft_atoi(char *str, t_stack **a, char **sent)
{
	int			neg;
	long int	nbr;

	nbr = 0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	if (*str == '\0')
		error_exit_all(a, sent);
	while (*str)
	{
		nbr = *str - '0' + nbr * 10;
		if (neg == -1 && nbr > 2147483648)
			error_exit_all(a, sent);
		else if (neg != -1 && nbr > INT_MAX)
			error_exit_all(a, sent);
		str++;
	}
	return ((int)nbr * neg);
}

bool	trie_ok(t_stack **a)
{
	t_stack	*curr;
	t_stack	*cmp;

	curr = *a;
	while (curr->next != NULL)
	{
		cmp = curr->next;
		if (curr->nbr > cmp->nbr)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	nbr_box(t_stack **a)
{
	t_stack	*curr;
	int		i;

	curr = *a;
	i = 0;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
