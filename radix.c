/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 14:12:40 by candace       #+#    #+#                 */
/*   Updated: 2022/10/18 13:02:17 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	bisempty(int *stacka, int *stackb)
{
	int	cnt;
	int	len;

	cnt = 0;
	len = arraylen(stackb);
	while (cnt < len)
	{
		pa(stacka, stackb);
		cnt++;
	}
}

void	sort(int *stacka, int arraylen)
{
	int	cnt;
	int	i;
	int	*stackb;
	int	maxbits;

	i = 0;
	stackb = createb(stacka);
	maxbits = 0;
	while (((arraylen + 1) >> maxbits) != 0)
		++maxbits;
	while (i < maxbits)
	{
		cnt = 0;
		while (cnt < arraylen)
		{
			if (((stacka[0] >> i) & 1) == 1)
				ra(stacka);
			else
				pb(stacka, stackb);
			cnt++;
		}
		i++;
		bisempty(stacka, stackb);
	}
}
