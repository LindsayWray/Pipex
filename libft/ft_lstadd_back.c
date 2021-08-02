/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 17:36:53 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/17 21:37:34 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_element **stack, t_element *new)
{
	t_element	*last;

	if (stack && *stack)
	{
		last = ft_lstlast(*stack);
		if (last)
			last->next = new;
	}
	else if (stack)
		*stack = new;
}
