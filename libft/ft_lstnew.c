/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 18:09:47 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/17 21:04:35 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_lstnew(void *content)
{
	t_element	*element;

	element = (t_element *)malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
