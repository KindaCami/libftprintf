#include    "ft_printf.h"

void	ft_puthex(unsigned long n, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		ft_puthex(n / 16, c);
	write(1, &base[n % 16], 1);
}

int	ft_hexlen(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static  int put_hex_content(unsigned int n, t_flags *flags, char c, int h_len)
{
    int count;

    count = 0;
    if (flags->hash && n != 0 && !flags->zero)
    {
        if  (c == 'x')
            count += write(1, "0x", 2);
        else
            count += write(1, "0X", 2);
    }
    if  (flags->precision > h_len)
        count += ft_putnchar('0', flags->precision - h_len);
    if (h_len > 0)
        ft_puthex(n, c);
    return (count + h_len);
}

static int	print_hex_format(unsigned int n, int total, t_flags *fl, char c)
{
	int		count;
	int		h_len;
	char	pad;

	h_len = ft_hexlen(n);
	if (fl->dot && fl->precision == 0 && n == 0)
		h_len = 0;
	count = 0;
	pad = ' ';
	if (fl->zero)
		pad = '0';
	if (fl->zero && fl->hash && n != 0)
	{
		count += write(1, "0", 1);
		count += write(1, &c, 1);
	}
	if (!fl->dash)
		count += ft_putnchar(pad, fl->width - total);
	count += put_hex_content(n, fl, c, h_len);
	if (fl->dash)
		count += ft_putnchar(' ', fl->width - total);
	return (count);
}

int	handle_hex(t_flags *flags, va_list *args, char c)
{
	unsigned int	n;
	int				h_len;
	int				total;

	n = va_arg(*args, unsigned int);
	h_len = ft_hexlen(n);
	if (flags->dot && flags->precision == 0 && n == 0)
		h_len = 0;
	total = h_len;
	if (flags->precision > h_len)
		total = flags->precision;
	if (flags->hash && n != 0)
		total += 2;
	if (flags->dot || flags->dash)
		flags->zero = 0;
	return (print_hex_format(n, total, flags, c));
}