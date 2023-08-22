#include "main.h"
#include <stdio.h>

/**
 *per_print - a func that print a per
 *@args: the arg given in the format
 *@buff: the buffer array for handling the print
 *@flg: available falg
 *@wd: the width
 *@per: pres (mainly for float)
 *@s: the size given
 *Return: nbr of char printed
 */


int per_print(va_list args, char buff[], int flg, int wd, int per, int s)
{
	CLEAR(args);
	CLEAR(buff);
	CLEAR(flg);
	CLEAR(wd);
	CLEAR(per);
	CLEAR(s);
	return (write(1, "%%", 1));
}
/**
 * ptr_print - print the pointer value
 * @args: the types of the args
 * @buff: the buff arr
 * @flg: active flags
 * @wd: the wd
 * @per: Per
 * @s: the len of the sef
 * Return: nbr printed
 */
int ptr_print(va_list args, char buff[],
	int flg, int wd, int per, int s)
{
	char m_char = 0, pad = ' ';
	int index = BUFFER_SIZE - 2, len = 2, pad_s = 1;
	unsigned long n_ad;
	char map_to[] = "0123456789abcdef";
	void *addr = va_arg(args, void *);

	CLEAR(wd);
	CLEAR(s);

	if (!addr)
		return (write(1, "(nil)", 5));

	buff[BUFFER_SIZE - 1] = '\0';
	CLEAR(per);

	n_ad = (unsigned long)addr;

	while (n_ad > 0)
	{
		buff[index--] = map_to[n_ad % 16];
		n_ad /= 16;
		len++;
	}

	if ((flg & Z) && !(flg & F_M))
		pad = '0';
	if (flg & F_P)
		m_char = '+', len++;
	else if (flg & S)
		m_char = ' ', len++;

	index++;

	return (ptr_printer(buff, index, len,
		wd, flg, pad, m_char, pad_s));
}

/**
 *bin_print - a func that print a bin
 *@args: the arg given in the format
 *@buff: the buffer array for handling the print
 *@flg: available falg
 *@wd: the width
 *@per: pres (mainly for float)
 *@s: the size given
 *Return: nbr of char printed
 */
int bin_print(va_list args, char buff[], int flg, int wd, int per, int s)
{
	unsigned int arr[32];
	unsigned int nbr, max, index, sum;
	int counter;

	CLEAR(buff);
	CLEAR(flg);
	CLEAR(wd);
	CLEAR(per);
	CLEAR(s);

	nbr = va_arg(args, unsigned int);
	max = UNS_MAX;
	arr[0] = nbr / max;

	for (index = 1; index < 32; index++)
	{
		max /= 2;
		arr[index] = (nbr / max) % 2;
	}
	for (index = 0, sum = 0, counter = 0; index < 32; index++)
	{
		sum += arr[index];
		if (sum || index == 31)
		{
			char z = '0' + arr[index];
				write(1, &z, 1);
			counter++;
		}
	}
	return (counter);
}
