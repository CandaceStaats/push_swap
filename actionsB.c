/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actionsB.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:02:24 by candace       #+#    #+#                 */
/*   Updated: 2022/10/18 11:14:36 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//sb swaps the top two numbers in stack b
void	sb(int *stackb)
{	
	int	temp;
	int	temp2;
	{
		temp = stackb[1];
		temp2 = stackb[0];
		stackb[0] = temp;
		stackb[1] = temp2;
		write(1, "sb\n", 3);
	}
}

// pb pushes a[0] to b[0]. Nothing if a is empty
void	pb(int *stacka, int *stackb)
{
	int	temp;
	int	temp2;
	int	cnt;

	if (stacka[0] == 0)
		return ;
	temp = stackb[0];
	temp2 = stacka[0];
	cnt = arraylen(stackb);
	while (cnt > 0)
	{
		stackb[cnt] = stackb[cnt - 1];
		cnt--;
	}
	stackb[0] = temp2;
	cnt = 0;
	while (cnt < arraylen(stacka) - 1)
	{
		temp = stacka[cnt + 1];
		stacka[cnt] = temp;
		cnt++;
	}
	stacka[cnt] = 0;
	write(1, "pb\n", 3);
}

//shifts all in stack B up one, first element becomes last
void	rb(int *stackb)
{
	int	cnt;
	int	*tempstack;
	int	temp;

	tempstack = createb(stackb);
	temp = stackb[0];
	cnt = 0;
	while (cnt < arraylen(stackb) - 1)
	{
		tempstack[cnt] = stackb[cnt + 1];
			cnt++;
	}
	tempstack[cnt] = temp;
	cnt = 0;
	while (cnt < arraylen(tempstack))
	{
		stackb[cnt] = tempstack[cnt];
		cnt++;
	}
	free(tempstack);
	write(1, "rb\n", 3);
}

// moves down all elements of B, last becomes first
void	rrb(int *stackb)
{
	int	cnt;
	int	*tempstack;
	int	temp;

	cnt = arraylen(stackb) - 1;
	tempstack = createb(stackb);
	temp = stackb[cnt];
	while (cnt > 0)
	{
		tempstack[cnt] = stackb[cnt - 1];
		cnt--;
	}
	tempstack[0] = temp;
	while (cnt < arraylen(stackb))
	{
		stackb[cnt] = tempstack[cnt];
		cnt++;
	}
	free(tempstack);
	write(1, "rrb\n", 4);
}
