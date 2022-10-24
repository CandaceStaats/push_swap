/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errorchecks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/08 14:07:19 by candace       #+#    #+#                 */
/*   Updated: 2022/10/20 14:40:39 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	*errorcheck(int argc, char **argv)
{
	int	n;

	n = 1;
	while (n != argc)
	{
		if (ft_isdigitstr(argv[n]) == -1)
		{
			write(1, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		n++;
	}
	return (0);
}

void	*errorchecks(int argc, char **argv)
{
	int		*list;
	long	n;
	long	temp;

	list = ft_calloc(sizeof(int), argc);
	if (list == NULL)
		return (NULL);
	n = 0;
	while (n++ < argc - 1)
	{
		temp = ft_atoi(argv[n]);
		if (temp < INT_MIN || temp > INT_MAX || ft_strlen(argv[n]) > 11)
		{
			write(1, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		list[n - 1] = temp;
		if (isduplicate(list, n - 1, list[n - 1]) == 1)
		{
			write(1, "Error\n", 7);
			free(list);
			exit(EXIT_FAILURE);
		}
	}
	return (list);
}

void	whichmethod(int *stacka, int arraylen)
{
	if (arraylen <= 3)
		method3(stacka, arraylen);
	else if (arraylen <= 5)
		method5(stacka, arraylen);
	else
		sort(stacka, arraylen);
	if (amisorted(stacka, arraylen) == 1)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

long	ft_atoi(char *str)
{
	long	res;
	long	cnt;
	long	pos;

	res = 0;
	cnt = 0;
	pos = 1;
	while (str[cnt] == '\n' || str[cnt] == ' ' || str[cnt] == '\t'
		|| str[cnt] == '\v' || str[cnt] == '\f' || str[cnt] == '\r')
		cnt++;
	if (str[cnt] == '-')
	{
		pos = -1;
		cnt++;
	}
	else if (str[cnt] == '+')
		cnt++;
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		res = res * 10 + str[cnt] - '0';
		cnt++;
	}
	return (res * pos);
}

size_t	ft_strlen(char const *str)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt] != 0)
	{
		cnt++;
	}
	return (cnt);
}
