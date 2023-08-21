#include "main.h"
/**
 * h_print - chose the func accodint to the type of it
 * @fomt: the foramt.
 * @ls: list of args
 * @i: i
 * @buff: buff array
 * @flg: how many flags
 * @wd: the width
 * @per: Presion specifiec
 * @s: the len size of it
 * Return: (I) or (II);
 */
int h_print(const char *fomt, int *i, va_list ls, char buff[],
	int flg, int wd, int per, int s)
{
	int index, u_len = 0, counter = -1;
	format_t fmt_types[] = {
	{'c', char_print}, {'s', str_print}, {'%', per_print},
	{'i', int_print}, {'d', int_print}, {'b', bin_print},
	{'u', u_print}, {'o', oc_print}, {'x', hex_print},
	{'X', hEX_print}, {'p', ptr_print}, {'S', un_print},
	{'r', rev_print}, {'R', rot_print}, {'\0', NULL}
};

	for (index = 0; fmt_types[index].fomt != '\0'; index++)
		if (fomt[*i] == fmt_types[index].fomt)
			return (fmt_types[index].func(ls, buff, flg, wd, per, s));

	if (fmt_types[index].fomt == '\0')
	{
		if (fomt[*i] == '\0')
			return (-1);
		u_len += write(1, "%%", 1);
		if (fomt[*i - 1] == ' ')
			u_len += write(1, " ", 1);
		else if (wd)
		{
			--(*i);
			while (fomt[*i] != ' ' && fomt[*i] != '%')
				--(*i);
			if (fomt[*i] == ' ')
				--(*i);
			return (1);
		}
		u_len += write(1, &fomt[*i], 1);
		return (u_len);
	}
	return (counter);
}

