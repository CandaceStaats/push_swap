/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 09:41:39 by candace       #+#    #+#                 */
/*   Updated: 2022/10/19 15:47:29 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int	*stacktemp;
	int	*stacka;

	errorcheck(argc, argv);
	stacktemp = errorchecks(argc, argv);
	stacka = indexarray(stacktemp, argc - 1);
	free(stacktemp);
	if (argc < 3)
	{
		free(stacka);
		return (0);
	}
	if (amisorted(stacka, argc - 1) == 1)
	{
		free(stacka);
		return (0);
	}
	else
		(whichmethod(stacka, argc - 1));
}
