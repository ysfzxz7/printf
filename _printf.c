#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
<<<<<<< HEAD
 * _print - Printf function
=======
 * _printf - Print function
>>>>>>> af88f9836daa6acedc57ff04e14c20ac1ea9c8dc
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
	int i, printed = 0, printed_chars = 0;
	int flags, width, precsion, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];
=======
	int index, prtd = 0, counter = 0;
	int flg, wd, per, s, buff_i = 0;
	va_list list;
	char buff[BUFFER_SIZE];
>>>>>>> af88f9836daa6acedc57ff04e14c20ac1ea9c8dc

	if (format == NULL)
		return (-1);

	va_start(list, format);

<<<<<<< HEAD
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precsion(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
					flags, width, precsion, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
=======
	for (index = 0; format && format[index] != '\0'; index++)
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
>>>>>>> af88f9836daa6acedc57ff04e14c20ac1ea9c8dc

	*buff_ind = 0;
}
