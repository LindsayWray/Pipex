/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_count.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:37:26 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:37:28 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	char_count(int plus_one)
{
	static int	count = 0;
	int			final_count;

	if (!plus_one)
	{
		final_count = count;
		count = 0;
		return (final_count);
	}
	count++;
	return (count);
}
