/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 13:07:54 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/17 19:04:52 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;
	unsigned char	*uc1;
	unsigned char	*uc2;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	count = 0;
	while (*uc1 == *uc2 && *uc1 != '\0' && count < (n - 1))
	{
		uc1++;
		uc2++;
		count++;
	}
	return (*uc1 - *uc2);
}
