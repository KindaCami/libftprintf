#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp_s;

	temp_s = (unsigned char *)s;
	while (n--)
	{
		*temp_s++ = (unsigned char)c;
	}
	return (s);
}

int	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}