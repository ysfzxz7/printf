#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * _write_char - Prints a string
 * @c: the type given.
 * @buff: a buff to handle it
 * @flg:  how many active flag.
 * @wd: get the width.
 * @per: thie pres
 * @s: the size
 *
 * Return: Nuber of char printed
 */
int _write_char(char c, char buff[],
	int flg, int wd, int per, int s)
{
	int index = 0;
	char pad = ' ';

	CLEAR(per);
	CLEAR(s);

	if (flg & Z)
		pad = '0';

	buff[index++] = c;
	buff[index] = '\0';

	if (wd > 1)
	{
		buff[BUFFER_SIZE - 1] = '\0';
		for (index = 0; index < wd - 1; index++)
			buff[BUFFER_SIZE - index - 2] = pad;

		if (flg & F_M)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFFER_SIZE - index - 1], wd - 1));
		else
			return (write(1, &buff[BUFFER_SIZE - index - 1], wd - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}


/**
 * write_nbr - Prints a string
 * @is_neg: negative
 * @index: index
 * @buff: buffer
 * @flg: flags
 * @wd: wd
 * @per: percentage
 * @s: string
 * @is_neg: Lista of arguments
 * @index: char types.
 * @buff: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wd: get width.
 * @per: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_neg, int index, char buff[],
	int flg, int wd, int per, int s)
{
	int len = BUFFER_SIZE - index - 1;
	char pad = ' ', m_char = 0;

	CLEAR(s);

	if ((flg & Z) && !(flg & F_M))
		pad = '0';
	if (is_neg)
		m_char = '-';
	else if (flg & F_P)
		m_char = '+';
	else if (flg & S)
		m_char = ' ';

	return (write_num(index, buff, flg, wd, per,
		len, pad, m_char));
}
/**
 * write_number - used to print numbers
 * @ind: the index
 * @buffer: the buffer
 * @flags: flags
 * @width: the width given
 * @prec: percsi
 * @length: The lenght of the number
 * @padd: the padding of the char
 * @extra_c: some other chars
 *
 * Return: return how many char printed
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_M && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_M) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_M) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * unsigned_printer - print number witout sign
 * @is_neg:check if a number is sign negative
 * @i: index to start printing a number
 * @buff: some chars
 * @flg: is there any speciefier
 * @wd: the wd of the speciefier
 * @per: Per of the speciefier
 * @s: the number of speciefier
 *
 * Return: Number of chars printed
 */
int unsigned_printer(int is_neg, int i,
	char buff[],
	int flg, int wd, int per, int s)
{
	int len = BUFFER_SIZE - i - 1, index = 0;
	char pad = ' ';

	CLEAR(is_neg);
	CLEAR(s);

	if (per == 0 && i == BUFFER_SIZE - 2 && buff[i] == '0')
		return (0);

	if (per > 0 && per < len)
		pad = ' ';

	while (per > len)
	{
		buff[--i] = '0';
		len++;
	}

	if ((flg & Z) && !(flg & F_M))
		pad = '0';

	if (wd > len)
	{
		for (index = 0; index < wd - len; index++)
			buff[index] = pad;

		buff[index] = '\0';

		if (flg & F_M)
		{
			return (write(1, &buff[i], len) + write(1, &buff[0], index));
		}
		else
		{
			return (write(1, &buff[0], index) + write(1, &buff[i], len));
		}
	}

	return (write(1, &buff[i], len));
}

/**
 * ptr_printer - prints an address
 * @buff: array of chars
 * @i: index to start printing
 * @len: the len
 * @wd: wd of the speci
 * @flg: flags
 * @pad: is the any spaces needed
 * @m_char: more chars
 * @pad_s: start spaces
 *
 * Return: counter of chars printed.
 */
int ptr_printer(char buff[], int i, int len,
	int wd, int flg, char pad, char m_char, int pad_s)
{
	int index;

	if (wd > len)
	{
		for (index = 3; index < wd - len + 3; index++)
			buff[index] = pad;
		buff[index] = '\0';
		if (flg & F_M && pad == ' ')
		{
			buff[--i] = 'x';
			buff[--i] = '0';
			if (m_char)
				buff[--i] = m_char;
			return (write(1, &buff[i], len) + write(1, &buff[3], index - 3));
		}
		else if (!(flg & F_M) && pad == ' ')
		{
			buff[--i] = 'x';
			buff[--i] = '0';
			if (m_char)
				buff[--i] = m_char;
			return (write(1, &buff[3], index - 3) + write(1, &buff[i], len));
		}
		else if (!(flg & F_M) && pad == '0')
		{
			if (m_char)
				buff[--pad_s] = m_char;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[pad_s], index - pad_s) +
				write(1, &buff[i], len - (1 - pad_s) - 2));
		}
	}
	buff[--i] = 'x';
	buff[--i] = '0';
	if (m_char)
		buff[--i] = m_char;
	return (write(1, &buff[i], BUFFER_SIZE - i - 1));
}
