/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 10:23:45 by candace       #+#    #+#                 */
/*   Updated: 2022/10/20 14:37:18 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}				t_list;
long	ft_atoi(char *str);
int		ft_isdigitstr(char *str);
int		isduplicate(int *array, int size, int value);
void	*errorchecks(int argc, char **argv);
void	whichmethod(int *stacka, int arraylen);
int		arraylen(int *arr);
int		*indexarray( int *array, int size);
void	sa(int *stacka);
void	pa(int *stacka, int *stackb);
void	ra(int *stacka);
void	rra(int *stacka);
void	sb(int *stackb);
void	pb(int *stacka, int *stackb);
void	rb(int *stackb);
void	rrb(int *stackb);
void	ss(int *stacka, int *stackb);
void	rr(int *stacka, int *stackb);
void	rrr(int *stacka, int *stackb);
void	method4(int *stacka);
void	repeat4(int *stacka);
int		method3(int *stacka, int arraylen);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
int		amisorted(int *stacka, int arraylen);
void	*errorcheck(int argc, char **argv);
int		*createb(int *stacka);
void	sort(int *stacka, int arraylen);
int		isminimum(int *array, int size, int *min, int *lowest_idx);
void	wheres5(int *stacka);
void	method5(int *stacka, int arraylen);
size_t	ft_strlen(char const *str);
#endif