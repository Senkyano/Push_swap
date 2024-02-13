/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:06:04 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/13 14:33:55 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/swaplib.h"

void	check_trie(t_stack **a, int ok);

int	main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		ok;
	char	*move;

	ok = 0;
	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	build_in(&a, argv);
	move = get_next_line(STDIN_FILENO);
	while (move)
	{
		ok = ope_do(&a, &b, move, ok);
		free(move);
		move = get_next_line(STDIN_FILENO);
	}
	if (move != NULL)
		free(move);
	check_trie(&a, ok);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

void	check_trie(t_stack **a, int ok)
{
	if (check_trie(&a) && ok == 0)
		write(1, "OK\n", 3);
	else if (check_trie(&a) == 0 && ok == 0)
		write(1, "KO\n", 3);
	else if (ok == 1)
		write(1, "Error\n", 6);
}
