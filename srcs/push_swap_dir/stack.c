/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:34:41 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/18 16:37:20 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

t_stack	*box(int value)
{
	t_stack	*box;

	box = malloc(sizeof(t_stack));
	if (!box)
		return (NULL);
	box->nbr = value;
	box->pile = 'a';
	box->next = NULL;
	return (box);
}

void	add_box(t_stack	**a, t_stack *box)
{
	t_stack	*curr;

	curr = *a;
	if (!(*a))
		*a = box;
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = box;
	}
}

void	build_in(t_stack **a, const char **argv)
{
	t_data	in;

	in.i = 0;
	while (argv[++in.i])
	{
		in.sent = ft_split(argv[in.i], a);
		in.j = -1;
		if (argv[in.i][0] == 0)
			error_exit_all(a, in.sent);
		while (in.sent[++in.j])
		{
			if (onlydigit(in.sent[in.j]))
			{
				in.box = box(ft_atoi(in.sent[in.j], a, in.sent));
				if (!in.box)
					error_exit_all(a, in.sent);
				add_box(a, in.box);
			}
			else
				error_exit_all(a, in.sent);
		}
		freesplit(in.sent);
	}
}

void	free_stack(t_stack **a)
{
	t_stack	*curr;

	while (*a)
	{
		curr = (*a)->next;
		free(*a);
		(*a) = curr;
	}
}

int	three_good(t_stack **pile)
{
	t_stack	*fst;
	t_stack	*sec;
	t_stack	*thr;

	fst = *pile;
	sec = fst->next;
	thr = sec->next;
	if (fst->nbr < sec->nbr && sec->nbr < thr->nbr)
		return (1);
	return (0);
}
