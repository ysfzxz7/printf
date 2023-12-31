#include "main.h"
/**
 *int_print - a func that print a int
 *@args: the arg given in the format
 *@buff: the buffer array for handling the print
 *@flg: available falg
 *@wd: the width
 *@per: pres (mainly for float)
 *@s: the size given
 *Return: nbr of char printed
 */
int int_print(va_list args, char buff[],
	int flg, int wd, int per, int s)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = converter_S_n(n, s);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buff, flg, wd, per, s));
}

