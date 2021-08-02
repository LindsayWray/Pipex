/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 13:07:54 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/22 19:04:52 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequal(char *s1, char *s2)
{
	unsigned char	*uc1;
	unsigned char	*uc2;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	while (*uc1 == *uc2 && *uc1 != '\0')
	{
		uc1++;
		uc2++;
	}
	if (*uc1 == *uc2)
		return (1);
	return (0);
}
