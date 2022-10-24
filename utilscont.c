/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilscont.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 14:34:54 by candace       #+#    #+#                 */
/*   Updated: 2022/10/17 11:45:34 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	arraylen(int *arr)
// This works when there is no 0 element in the array
{
	int	cnt;

	cnt = 0;
	while (arr[cnt] != 0)
		cnt++;
	return (cnt);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pnt;

	pnt = malloc(nitems * size);
	if (pnt == NULL)
		return (NULL);
	ft_bzero(pnt, (nitems * size));
	return (pnt);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cnt;

	cnt = (unsigned char *)s;
	while (n)
	{
		n--;
		*cnt = 0;
		cnt++;
	}
}

int	amisorted(int *stacka, int arraylen)
// Check to see if the numbers are sorted
{
	int	cnt;

	cnt = 0;
	while (cnt < arraylen - 1)
	{
		if (stacka[cnt] < stacka[cnt + 1])
			cnt++;
		else
			return (0);
	}
	return (1);
}

int	*createb(int *stacka)
{
	int	*stackb;

	stackb = ft_calloc(sizeof(int), arraylen(stacka) + 1);
	if (stackb == NULL)
		return (NULL);
	return (stackb);
}
