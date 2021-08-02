/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 18:07:21 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/17 21:38:42 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_element **lst, t_element *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
