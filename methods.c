/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   methods.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 12:08:01 by candace       #+#    #+#                 */
/*   Updated: 2022/10/18 13:31:22 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	method3(int *stacka, int arraylen)
{
	if (arraylen == 2)
	{
		if (!(stacka[0] < stacka[1]))
			sa(stacka);
	}
	while (arraylen == 3 && amisorted(stacka, 3) != 1)
	{
		if (stacka[0] == 2 && stacka[1] == 1 && stacka[2] == 3)
			sa(stacka);
		if (stacka[0] == 3 && stacka[1] == 2 && stacka[2] == 1)
		{
			sa(stacka);
			rra(stacka);
		}
		if (stacka[0] == 3 && stacka[1] == 1 && stacka[2] == 2)
			ra(stacka);
		if (stacka[0] == 1 && stacka[1] == 3 && stacka[2] == 2)
		{
			sa(stacka);
			ra(stacka);
		}
		if (stacka[0] == 2 && stacka[1] == 3 && stacka[2] == 1)
			rra(stacka);
	}
	return (0);
}

void	method4(int *stacka)
{
	while (!(stacka[0] < stacka[1] && stacka[1] < stacka[2]
			&& stacka[2] < stacka[3]))
	{
		if (stacka[0] == 4)
			repeat4(stacka);
		else if (stacka[1] == 4)
		{
			sa(stacka);
			repeat4(stacka);
		}
		else if (stacka[3] == 4)
		{
			rra(stacka);
			repeat4(stacka);
		}
		else if (stacka[2] == 4)
		{
			rra(stacka);
			rra(stacka);
			repeat4(stacka);
		}
	}
}

void	repeat4(int *stacka)
{
	int	temp;
	int	*tempstack;

	temp = stacka[0];
	tempstack = createb(stacka);
	write(1, "pb\n", 3);
	tempstack[0] = stacka[1];
	tempstack[1] = stacka[2];
	tempstack[2] = stacka[3];
	method3(tempstack, 3);
	stacka[1] = tempstack[0];
	stacka[2] = tempstack[1];
	stacka[3] = tempstack[2];
	stacka[0] = temp;
	free(tempstack);
	write(1, "pa\n", 3);
	if (stacka[0] == 4)
		ra(stacka);
}

void	method5(int *stacka, int arraylen)
{
	int	*stackb;

	stackb = createb(stacka);
	if (arraylen == 4)
	{
		method4(stacka);
		free(stacka);
		exit(EXIT_SUCCESS);
	}
	if (!(stacka[0] == 5))
		wheres5(stacka);
	pb(stacka, stackb);
	method4(stacka);
	pa(stacka, stackb);
	ra(stacka);
	free(stackb);
}

void	wheres5(int *stacka)
{
	if (stacka[1] == 5)
		sa(stacka);
	if (stacka[4] == 5)
		rra(stacka);
	if (stacka[3] == 5)
	{
		rra(stacka);
		rra(stacka);
	}
	if (stacka[2] == 5)
	{
		ra(stacka);
		ra(stacka);
	}
}
