/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 15:11:19 by lwray         #+#    #+#                 */
/*   Updated: 2020/12/11 18:06:25 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_lstlast(t_element *last)
{
	if (last == NULL)
		return (NULL);
	while ((last->next) != NULL)
		last = (last->next);
	return (last);
}
