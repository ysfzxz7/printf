#include "main.h"

/**
 * unprint - print the pointer value
 * @args: the types of the args
 * @buff: the buff arr
 * @flg: active flags
 * @wd: the wd
 * @per: Per
 * @s: the len of the sef
 * Return: nbr printed
 */

int un_print(va_list args, char buff[],
	int flg, int wd, int per, int s)
{
	int index = 0, os = 0;
	char *string = va_arg(args, char *);

	CLEAR(flg);
	CLEAR(wd);
	CLEAR(per);
	CLEAR(s);

	if (!string)
		return (write(1, "(null)", 6));

	while (string[index] != '\0')
	{
		if (printable(string[index]))
			buff[index + os] = string[index];
		else
			os += add_hexa(string[index], buff, index + os);

		index++;
	}

	buff[index + os] = '\0';

	return (write(1, buff, index + os));
}

/**
 * rev_print - print string in rev
 * @args: the types of the args
 * @buff: the buff arr
 * @flg: active flags
 * @wd: the wd
 * @per: Per
 * @s: the len of the sef
 * Return: nbr printed
 */

int rev_print(va_list args, char buff[],
	int flg, int wd, int per, int s)
{
	char *string;
	int index, counter = 0;

	CLEAR(buff);
	CLEAR(flg);
	CLEAR(wd);
	CLEAR(s);

	string = va_arg(args, char *);

	if (!string)
	{
		CLEAR(per);

		string = ")Null(";
	}

	for (index = 0; string[index]; index++)
		;
	for (index = index - 1; index >= 0; index--)
	{
		char k = string[index];

		write(1, &k, 1);
		counter++;
	}
	return (counter);
}

/**
 * rot_print - rotat a string 13
 * @args: the type of args
 * @buff: the buff arr
 * @flg: active flags
 * @wd: the wd
 * @per: Per
 * @s: the len of the sef
 * Return: nbr printed
 */


int rot_print(va_list args, char buff[],
	int flg, int wd, int per, int s)
{
	char k;
	char *string;
	unsigned int index, j;
	int counter = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(args, char *);
	CLEAR(buff);
	CLEAR(flg);
	CLEAR(wd);
	CLEAR(per);
	CLEAR(s);

	if (!string)
		string = "(AHYY)";
	for (index = 0; string[index]; index++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == string[index])
			{
				k = out[j];
				write(1, &k, 1);
				counter++;
				break;
			}
		}
		if (!input[j])
		{
			k = string[index];
			write(1, &k, 1);
			counter++;
		}
	}
	return (counter);
}
