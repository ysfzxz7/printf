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
