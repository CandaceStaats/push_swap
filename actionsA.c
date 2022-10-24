/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actionsA.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/17 14:36:01 by candace       #+#    #+#                 */
/*   Updated: 2022/10/18 11:52:06 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//sa swaps the top two numbers in stack a
void	sa(int *stacka)
{	
	int	temp;
	int	temp2;
	{
		temp = stacka[1];
		temp2 = stacka[0];
		stacka[0] = temp;
		stacka[1] = temp2;
		write(1, "sa\n", 3);
	}
}

// pa pushes b[0] to a[0]. Nothing if b is empty
void	pa(int *stacka, int *stackb)
{
	int	temp;
	int	temp2;
	int	cnt;

	if (stackb[0] == 0)
		return ;
	temp = stacka[0];
	temp2 = stackb[0];
	cnt = arraylen(stacka);
	while (cnt > 0)
	{
		stacka[cnt] = stacka[cnt - 1];
		cnt--;
	}
	stacka[0] = temp2;
	cnt = 0;
	while (cnt < arraylen(stackb) - 1)
	{
		temp = stackb[cnt + 1];
		stackb[cnt] = temp;
		cnt++;
	}
	stackb[cnt] = 0;
	write(1, "pa\n", 3);
}

//shifts all in stack A up one, first element becomes last
void	ra(int *stacka)
{
	int	cnt;
	int	*tempstack;
	int	temp;

	tempstack = createb(stacka);
	temp = stacka[0];
	cnt = 0;
	while (cnt < arraylen(stacka) - 1)
	{
		tempstack[cnt] = stacka[cnt + 1];
			cnt++;
	}
	tempstack[cnt] = temp;
	cnt = 0;
	while (cnt < arraylen(tempstack))
	{
		stacka[cnt] = tempstack[cnt];
		cnt++;
	}
	free(tempstack);
	write(1, "ra\n", 3);
}

// moves down all elements of a, last becomes first
void	rra(int *stacka)
{
	int	cnt;
	int	*tempstack;
	int	temp;

	cnt = arraylen(stacka) - 1;
	tempstack = createb(stacka);
	temp = stacka[cnt];
	while (cnt > 0)
	{
		tempstack[cnt] = stacka[cnt - 1];
		cnt--;
	}
	tempstack[0] = temp;
	while (cnt < arraylen(stacka))
	{
		stacka[cnt] = tempstack[cnt];
		cnt++;
	}
	free(tempstack);
	write(1, "rra\n", 4);
}
