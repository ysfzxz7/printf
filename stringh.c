#include "main.h"

/**
 *char_print - a func that print a string
 *@args: the arg given in the format
 *@buff: the buffer array for handling the print
 *@flg: available falg
 *@wd: the width
 *@per: pres (mainly for float)
 *@s: the size given
 *Return: nbr of char printed
 */
int char_print(va_list args, char buff[], int flg, int wd, int per, int s)
{
	char chaar = va_arg(args, int);

	return (_write_char(chaar, buff, flg, wd, per, s));
}

/**
 *str_print - a func that print a string
 *@args: the arg given in the format
 *@buff: the buffer array for handling the print
 *@flg: available falg
 *@wd: the width
 *@per: pres (mainly for float)
 *@s: the size given
 *Return: nbr of char printed
 */

int str_print(va_list args, char buff[], int flg, int wd, int per, int s)
{
	int len = 0, index;
	char *string = va_arg(args, char *);

	CLEAR(buff);
	CLEAR(flg);
	CLEAR(wd);
	CLEAR(per);
	CLEAR(s);
	if (!string)
	{
		string = NULL_STRING;
		if (per >= 6)
			string = "      ";
	}
	while (string[len] != '\0')
		len++;
	if (per >= 0 && per < len)
		len = per;

	if (wd > len)
	{
		if (flg & F_M)
		{
			write(1, &string[0], len);
			for (index = wd - len; index > 0; index--)
				write(1, " ", 1);
			return (wd);
		}
		else
		{
			for (index = wd - len; index > 0; index--)
				write(1, " ", 1);
			write(1, &string[0], len);
			return (wd);
		}
	}
	return (write(1, string, len));
}
