#include "main.h"

/**
 * size - count the size of an arg
 * @placeholder: the char of placeholders
 * @index: list of args.
 *
 * Return: Per
 */
int size(const char *placeholder, int *index)
{
	int c_index = *index + 1;
	int s = 0;

	if (placeholder[c_index] == 'l')
		s = S_L;
	else if (placeholder[c_index] == 'h')
		s = S_SH;

	if (s == 0)
		*index = c_index - 1;
	else
		*index = c_index;

	return (s);
}

/**
 * wd - Calculat the wd
 * @placeholer: the string containg the args
 * @index: index of args
 * @args: list of args
 *
 * Return: wd
 */
int _wd(const char *placeholder, int *index, va_list args)
{
	int c_index;
	int wd = 0;

	for (c_index = *index + 1; placeholder[c_index] != '\0'; c_index++)
	{
		if (digit(placeholder[c_index]))
		{
			wd *= 10;
			wd += placeholder[c_index] - '0';
		}
		else if (placeholder[c_index] == '*')
		{
			c_index++;
			wd = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*index = c_index - 1;

	return (wd);
}
