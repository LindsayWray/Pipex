/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 10:07:30 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/28 17:00:03 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# define NULLSTR "(null)"

typedef struct s_flagstruct
{
	int	width;
	int	left_aligned;
	int	zeroes;
	int	precision;
}				t_flagstruct;

t_flagstruct	flagcheck(char *str, va_list ap);
void			ft_putchar(char c);
void			ft_putnstr(char *str, int n);
void			ft_putnbr(int nb);
void			ft_putnbr_uns(unsigned int nb);
void			ft_putptr(unsigned long addr, int padding);
void			ft_conversion(va_list ap, char conv, t_flagstruct flags);
void			flags_d(int input, t_flagstruct flags);
void			flags_u(unsigned int input, t_flagstruct flags);
void			flags_c(int input, t_flagstruct flags);
void			flags_x(unsigned int input, char *base, t_flagstruct flags);
void			flags_s(char *input, t_flagstruct flags);
void			flags_p(void *input, t_flagstruct flags);
void			flags_null(t_flagstruct flags);
int				is_specifier(char c);
long			print_padding(int padding, long input);
void			print_space(int spaces);
void			ft_putnbr_hexa(unsigned long input, char *base);
int				hexa_len(unsigned long nbr);
int				char_count(int plus_one);
int				strlen_or_precision(char *str, int precision);
void			flags_f(double input, t_flagstruct flags);
void			ft_putdecimal(long double decimal, int dec_len);
int				int_len(long n);
double			decimal_rounding(double input, int dec_len);
int				ft_printf(const char *format, ...);
#endif