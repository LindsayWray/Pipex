/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hexa_len.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:42:04 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:42:06 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	hexa_len(unsigned long nbr)
{
	int	len;

	len = 1;
	while (nbr / 16 > 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

int	int_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}
