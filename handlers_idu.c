#include "ft_printf.h"

int	print_int_aux(long n, char sign,int num_len,t_flags *flags)
{
	int	count;

	count = 0;
	if (sign != 0)
		count += write(1, &sign, 1);
	if (flags->precision > num_len)
		count += ft_putnchar('0', flags->precision - num_len);
	if (num_len > 0)
	{
		if (n < 0)
			count += ft_putnbr_unsigned(-n);
		else
			count += ft_putnbr_unsigned(n);
	}
	return (count);
}

static int	print_int_format(long n, int n_len, int p_len, t_flags *flags)
{
	int		count;
	char	sign;
	char	pad_c;
	char	s_send;

	count = 0;
	sign = ft_numbers_sign((int)n, flags);
	pad_c = ' ';
	if (flags->zero)
		pad_c = '0';
	s_send = sign;
	if (flags->zero)
		s_send = 0;
	if (flags->zero && sign)
		count += write(1, &sign, 1);
	if (!flags->dash)
		count += ft_putnchar(pad_c, flags->width - p_len);
	count += print_int_aux(n, s_send, n_len, flags);
	if (flags->dash)
		count += ft_putnchar(' ', flags->width - p_len);
	return (count);
}

int	handle_int(t_flags *flags, va_list *args)
{
	long	n;
	int		n_len;
	int		p_len;

	n = (long)va_arg(*args, int);
	n_len = ft_numlen(n);
	if (flags->dot && flags->precision == 0 && n == 0)
		n_len = 0;
	p_len = n_len;
	if (flags->precision > n_len)
		p_len = flags->precision;
	if (ft_numbers_sign((int)n, flags))
		p_len++;
	if (flags->dot || flags->dash)
		flags->zero = 0;
	return (print_int_format(n, n_len, p_len, flags));
}

static int	print_u_format(unsigned int n, int n_len, int p_len, t_flags *flags)
{
	int		count;
	char	pad_c;

	count = 0;
	pad_c = ' ';
	if (flags->zero)
		pad_c = '0';
	if (!flags->dash)
		count += ft_putnchar(pad_c, flags->width - p_len);
	count += print_int_aux((long)n, 0, n_len, flags);
	if (flags->dash)
		count += ft_putnchar(' ', flags->width - p_len);
	return (count);
}

int	handle_unsigned(t_flags *flags, va_list *args)
{
	unsigned int	n;
	int				n_len;
	int				p_len;

	n = va_arg(*args, unsigned int);
	n_len = ft_numlen((long)n);
	if (flags->dot && flags->precision == 0 && n == 0)
		n_len = 0;
	p_len = n_len;
	if (flags->precision > n_len)
		p_len = flags->precision;
	if (flags->dot || flags->dash)
		flags->zero = 0;
	return (print_u_format(n, n_len, p_len, flags));
}