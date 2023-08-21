#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
/*some flags*/
#define F_M 1
#define F_P 2
#define Z 4
#define H 8
#define S 16

#define S_SH 1
#define S_L 2


/*define the null string*/
#define NULL_STRING "(null)"
#define BUFFER_SIZE 1024
#define UNS_MAX 2147483684 
#define CLEAR(x) (void)(x)
/**
 *sturct format - struct op;
 *@ident: the identifier
 *
 *@func: the function pointer
 */
struct format
{
	char fomt;
	int (*func)(va_list,char[], int, int, int, int);
};

/**
 *typedef this struct format into format_t
 */
typedef struct format format_t;



/**/
int _printf(const char *format, ...);
/*TODO handle printf*/
int h_print(const char *fomrat, int *i, va_list ls, char buff[], int flg, int wd, int per, int s);
/*white handling*/
int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c);
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);

int _write_char(char c, char buff[], int flg, int wd, int per, int s);
int unsigned_printer(int is_neg, int i, char buff[], int flg, int wd, int per, int s);
int ptr_printer(char buff[], int i, int len, int wd, int flg, char pad, char m_char, int pad_s);

/*you can find these func in the func1.c file*/

int int_print(va_list args, char buff[], int flg, int wd, int per, int s);
int char_print(va_list args, char buff[], int flg, int wd, int per, int s);
int str_print(va_list args, char buff[], int flg, int wd, int per, int s);
int per_print(va_list args, char buff[], int flg, int wd, int per, int s);
int bin_print(va_list args, char buff[], int flg, int wd, int per, int s);


/*you can find this funcs int func2*/
int hex_print(va_list args, char buff[],int flg, int wd, int per, int s);
int u_print(va_list args, char buff[], int flg, int wd, int per, int s);
int oc_print(va_list args, char buff[], int flg, int wd, int per, int s);
int hEX_print(va_list args, char buff[], int flg, int wd, int per, int s);
int hexa_print(va_list args, char map_to[], char buff[], int flg, char flg_c, int wd, int per, int s);

/*this func in the func3 folder*/
int ptr_print(va_list args, char buff[], int flg, int wd, int per, int s);
int un_print(va_list args, char buff[], int flg, int wd, int per, int s);
int rev_print(va_list args, char buff[], int flg, int wd, int per, int s);
int rot_print(va_list args, char buff[], int flg, int wd, int per, int s);


int bX_print(char *bX);

/*det wd s and flg per*/
int flags(const char *format, int *i);
int _wd(const char *format, int *i, va_list list);
int pers(const char *format, int *i, va_list list);
int size(const char *format, int *i);


/*this the putchar func*/
int _putchar(char);
/*you cn find these func in the utiles file*/
/*useful functions*/
int printable(char);
int digit(char);
int add_hexa(char, char[], int);

/*converter*/
long int converter_S_u(unsigned long int n, int s);
long int converter_S_n(long int n, int s);
#endif
