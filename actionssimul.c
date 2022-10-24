/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actionssimul.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:08:04 by candace       #+#    #+#                 */
/*   Updated: 2022/09/06 09:22:19 by candace       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ss(int *stacka, int *stackb)
{
	sa(stacka);
	sb(stackb);
	write(1, "ss\n", 3);
}

void	rr(int *stacka, int *stackb)
{
	ra(stacka);
	rb(stackb);
	write(1, "rr\n", 3);
}

void	rrr(int *stacka, int *stackb)
{
	rra(stacka);
	rrb(stackb);
	write(1, "rrr\n", 4);
}
