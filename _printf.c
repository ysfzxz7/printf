#include "main.h"

void buff_print(char buff[], int *buff_i);

/**
 * _printf - Print function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int index, prtd = 0, counter = 0;
	int flg, wd, per, s, buff_i = 0;
	va_list list;
	char buff[BUFFER_SIZE];

	if (!format)
		return (-1);

	va_start(list, format);

	for (index = 0; format && format[index] != '0' ; index++)
	{
		if (format[index] != '%')
		{
			buff[buff_i++] = format[index];
			if (buff_i == BUFFER_SIZE)
				buff_print(buff, &buff_i);
			counter++;
		}
		else
		{
			buff_print(buff, &buff_i);
			flg = flags(format, &index);
			wd = _wd(format, &index, list);
			per = pers(format, &index, list);
			s = size(format, &index);
			++index;
			prtd = h_print(format, &index, list, buff,
				flg, wd, per, s);
			if (prtd == -1)
				return (-1);
			counter += prtd;
		}
	}

	buff_print(buff, &buff_i);

	va_end(list);

	return (counter);
}
/**
 * buff_print - pirnt the placeholder if it is exist
 * @buff: a ptr to the char
 * @buff_i: the len.
 */
void buff_print(char buff[], int *buff_i)
{
	if (*buff_i > 0)
		write(1, &buff[0], *buff_i);
	*buff_i = 0;
}
