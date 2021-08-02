/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 15:11:19 by lwray         #+#    #+#                 */
/*   Updated: 2020/12/13 14:11:25 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_element *lst)
{
	int	count;

	if (lst == NULL)
		return (0);
	count = 1;
	while ((lst->next) != NULL)
	{
		lst = (lst->next);
		count++;
	}
	return (count);
}
