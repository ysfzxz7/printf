#include "main.h"

/**
 * u_print - print some unsigned number
 * @args: the args
 * @buff: Buff arr that contain the args
 * @flg: how mant active flag
 * @wd: the withd
 * @per: per
 * @s: the siz of the per
 * Return: the counter of printed char
 */
int u_print(va_list args, char buff[],
	int flg, int wd, int per, int s)
{
	int index = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);

	number = converter_S_u(number, s);

	if (number == 0)
		buff[index--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[index--] = (number % 10) + '0';
		number /= 10;
	}

	index++;

	return (unsigned_printer(0, index, buff, flg, wd, per, s));
}
/**
 * oc_print - print some unsigned number
 * @args: the args
 * @buff: Buff arr that contain the args
 * @flg: how mant active flag
 * @wd: the withd
 * @per: per
 * @s: the siz of the per
 * Return: the counter of printed char
 */


int oc_print(va_list args, char buff[],
	int flg, int wd, int per, int s)
{

	int index = BUFFER_SIZE - 2;
	unsigned long int nbr = va_arg(args, unsigned long int);
	unsigned long int init_number = nbr;

	CLEAR(wd);

	nbr = converter_S_u(nbr, s);

	if (nbr == 0)
		buff[index--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (nbr > 0)
	{
		buff[index--] = (nbr % 8) + '0';
		nbr /= 8;
	}

	if (flg & H && init_number != 0)
		buff[index--] = '0';

	index++;

	return (unsigned_printer(0, index, buff, flg, wd, per, s));
}

/**
 * hex_print - print some unsigned number
 * @args: the args
 * @buff: Buff arr that contain the args
 * @flg: how mant active flag
 * @wd: the withd
 * @per: per
 * @s: the siz of the per
 * Return: the counter of printed char
 */

int hex_print(va_list args, char buff[],
	int flg, int wd, int per, int s)
{
	return (hexa_print(args, "0123456789abcdef", buff,
		flg, 'x', wd, per, s));
}

/**
 * hEX_print - print some unsigned number
 * @args: the args
 * @buff: Buff arr that contain the args
 * @flg: how mant active flag
 * @wd: the withd
 * @per: per
 * @s: the siz of the per
 * Return: the counter of printed char
 */

int hEX_print(va_list args, char buff[],
	int flg, int wd, int per, int s)
{
	return (hexa_print(args, "0123456789ABCDEF", buff,
		flg, 'X', wd, per, s));
}

/**
 * hexa_print - print some unsigned number
 * @args: the args
 * @map_to: map to
 * @buff: Buff arr that contain the args
 * @flg: how mant active flag
 * @flg_c: the fla c
 * @wd: the withd
 * @per: per
 * @s: the siz of the per
 * Return: the counter of printed char
 */

int hexa_print(va_list args, char map_to[], char buff[],
	int flg, char flg_c, int wd, int per, int s)
{
	int index = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);
	unsigned long int in_n = number;

	CLEAR(wd);

	number = converter_S_u(number, s);

	if (number == 0)
		buff[index--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[index--] = map_to[number % 16];
		number /= 16;
	}

	if (flg & H && in_n != 0)
	{
		buff[index--] = flg_c;
		buff[index--] = '0';
	}

	index++;

	return (unsigned_printer(0, index, buff, flg, wd, per, s));
}
