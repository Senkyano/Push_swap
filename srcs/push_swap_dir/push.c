/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:20:40 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 16:20:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

void	push_to(t_stack **from, t_stack **to)
{
	t_stack	*first_room;

	if ((*from)->pile == 'a')
		(*from)->pile = 'b';
	else if ((*from)->pile == 'b')
		(*from)->pile = 'a';
	action("p", (*from)->pile);
	if (!(*to))
	{
		(*to) = *from;
		(*from) = (*from)->next;
		(*to)->next = NULL;
		return ;
	}
	first_room = (*from);
	(*from) = (*from)->next;
	first_room->next = (*to);
	(*to) = first_room;
}

void	action(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push_cmd(t_stack **from, t_stack **to)
{
	t_stack	*first_room;

	if ((*from)->pile == 'a')
		(*from)->pile = 'b';
	else if ((*from)->pile == 'b')
		(*from)->pile = 'a';
	if (!(*to))
	{
		(*to) = *from;
		(*from) = (*from)->next;
		(*to)->next = NULL;
		return ;
	}
	first_room = (*from);
	(*from) = (*from)->next;
	first_room->next = (*to);
	(*to) = first_room;
}
