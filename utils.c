/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 10:21:18 by candace       #+#    #+#                 */
/*   Updated: 2022/10/20 14:46:21 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigitstr(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] == 45)
			c++;
		if (str[c] < 48 || str[c] > 57)
		{
			return (-1);
		}
		c++;
	}
	return (0);
}

int	isduplicate(int *array, int size, int value)
{
	int	cnt;

	cnt = 0;
	while (cnt < size)
	{
		if (array[cnt] == value)
		{
			return (1);
		}
		cnt++;
	}
	return (0);
}

static int	find_lowest(int *array, int size, long min)
{
	int	i;
	int	lowest_idx;

	i = 0;
	while (i < size)
	{
		if (array[i] > min)
		{
			lowest_idx = i;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (array[i] < array[lowest_idx] && array[i] > min)
			lowest_idx = i;
		i++;
	}
	return (lowest_idx);
}

int	*indexarray(int *array, int size)
{
	int		i;
	long	min;
	int		lowest_idx;
	int		*out_array;

	min = (long)INT_MIN - 1;
	out_array = ft_calloc(sizeof(int), size + 1);
	if (!out_array)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		lowest_idx = find_lowest(array, size, min);
		out_array[lowest_idx] = i + 1;
		min = array[lowest_idx];
		i++;
	}
	out_array[size] = 0;
	return (out_array);
}
