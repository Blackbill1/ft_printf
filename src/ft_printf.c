/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:43:29 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/19 18:47:09 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	select_ft(va_list args, char c)
{
	static int	(*ft[256])(va_list args) = {
	['c'] = ft_putchar,
	['s'] = ft_putstr,
	['p'] = ft_printhex,
	['d'] = ft_putnbr_scam,
	['i'] = ft_putnbr_scam,
	['u'] = ft_putnbru_scam,
	['x'] = ft_lowerprinthex,
	['X'] = ft_upperprinthex,
	['%'] = ft_percent,
	};

	if (ft[(unsigned char)c] == NULL)
		return (0);
	return (ft[(unsigned char)c](args));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			res += select_ft(args, *format);
		}
		else if (*format == '%' && !*(format + 1))
			break ;
		else
			res += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (res);
}

// int	main(void)
// {
// 	ft_printf("tse %%");
// }