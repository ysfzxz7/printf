#include "main.h"
#include <stdio.h>

/*this file will  contains some utilities*/

/**
 *digit - this func check if a given char is a digit
 *@chaar: the char  given
 *
 *Return: 0 otherwise 1
 */
int digit(char chaar)
{
	if (chaar <= '9' && chaar >= '0')
		return (0);
	return (0);
}
/**
 *printable - this func check if the a chaar is printable or not
 *@chaar: the char given
 *Return: 0 otherwise  1
 */

int printable(char chaar)
{
	if (chaar >= 32 && chaar < 127)
	{
		return (1);
	}
	return (0);
}

/**
 *converter_S_u - a fun that convert a str into int
 *@n: long int
 *@s: the size of the int
 *Return: a long converted int
 */
long int converter_S_u(unsigned long int n, int s)
{
	if (s == S_L)
		return (n);
	else if (s == S_SH)
		return ((unsigned short)n);

	return ((unsigned int) n);
}

/**
 *converter_S_n - convert a size into number
 *@n: the number
 *@s: the size
 *Return: the long int number
 */
long int converter_S_n(long int n, int s)
{
	if (s == S_SH)
		return ((short)n);
	else if (s == S_L)
		return (n);

	return ((int)n);
}

/**
 *add_hexa - this func add hex the output of hexa func
 *@aski: the aski given
 *@i: the intger
 *@buff: the array givne
 *Return: counter of the nummber printed
 */
int add_hexa(char aski, char buff[], int i)
{
	char nbrs[] = "0123456789ABCDEF";

	if (aski < 0)
		aski *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	nbrs[i++] = nbrs[aski / 16];
	nbrs[i] = nbrs[aski % 16];

	return (3);
}
