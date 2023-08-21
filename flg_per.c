#include "main.h"
#include <stdarg.h>
/**
 * flags - how many active flag
 * @placeholder: the placeholder containg the args
 * @index: a single parm
 * Return: flg
 */
int flags(const char *placeholder, int *index)
{
	int k, c_index;
	int flg = 0;
	const char F_C[] = {'-', '+', '0', '#', ' ', '\0'};
	const int F_A[] = {F_M, F_P, Z, H, S, 0};

	for (c_index = *index + 1; placeholder[c_index] != '\0'; c_index++)
	{
		for (k = 0; F_C[k] != '\0'; k++)
			if (placeholder[c_index] == F_C[k])
			{
				flg |= F_A[k];
				break;
			}

		if (F_C[k] == 0)
			break;
	}

	*index = c_index - 1;

	return (flg);
}

/**
 * pers - calcul some per
 * @format: the string containg the string
 * @index: list of args
 * @list: variadic args.
 *
 * Return: Per
 */
int pers(const char *format, int *index, va_list list)
{
	int c_index = *index + 1;
	int per = -1;
	int p;

	if (format[c_index] != '.')
		return (per);

	per = 0;

	for (c_index += 1; format[c_index] != '\0'; c_index++)
	{
		if (digit(format[c_index]))
		{
			per *= 10;
			per += format[c_index] - '0';
		}
		else if (format[c_index] == '*')
		{
			c_index++;
			p = va_arg(list, int);

			break;
		}
		else
			break;
	}

	*index = c_index - 1;

	return (p);
}
