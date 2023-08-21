#include "main.h"

/**
 * print_id - print decimal numbers
 * @num: integer to print
 * Return; the number of characters printed
 */
int print_id(int a)
{
	int len = 0;
	if (a == -2147483648)
	{
		return (print_string(("-2147483648"));
				}
				if (a == 0)
				{
				_putchar('0');
				return (1);
				}
				if (a < 0)
				{
				_putchar('-');
				a = -a;
				len++;
				}
				if ((a / 10) != 0)
				{
				len += print_id(a / 10);
				}
				_putchar((a % 10) + '0');
				len++;
				return (len);
}
