#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "utils.h"

/**
 * @fn
 * print error message for red font color
 * @param msg error message string
 * @return is print correctly
 */
int
print_error(const char *msg, ...)
{
# define ERROR_VALUE -1;
	if (!msg) return ERROR_VALUE;

	va_list 		args;
	char			*error_string;
	const size_t	len_msg = strlen(msg);
	size_t			res;
# define COLOR_RED		"\x1b[31m"
# define COLOR_DEF		"\x1b[39m"
# define LEN_COLOR_RED	(sizeof(COLOR_RED) - 1)
# define LEN_COLOR_DEF	(sizeof(COLOR_DEF) - 1)
	error_string = malloc(
		LEN_COLOR_RED + LEN_COLOR_DEF + len_msg);
	if (!error_string) return ERROR_VALUE;

	strcpy(error_string, COLOR_RED);
	strcpy(error_string + LEN_COLOR_RED, msg);
	strcpy(
		error_string + LEN_COLOR_RED + len_msg,
		COLOR_DEF
	);
	strcpy(
		error_string + LEN_COLOR_RED + len_msg + LEN_COLOR_DEF,
		"\n\0"
	);

	va_start(args, msg);
	res = vfprintf(stderr, error_string, args);
	free(error_string);
	va_end(args);

	return res;
}

/**
 * @fn
 * compare 2 variables value to check same value
 * @param compare1 one of the compare variable
 * @param compare2 compare with compare1 variable
 * @param size the size of the 2 variables data type
 * @return is compare 2 variables are same value
 */
bool
is_same(void *compare1, void *compare2, uintptr_t size)
{
# define STANDARD_SIZE sizeof(unsigned char)
	int 			i;
	int				compare_times;
	unsigned char	*unsiged_compare1_pointer;
	unsigned char	*unsiged_compare2_pointer;

	unsiged_compare1_pointer = compare1;
	unsiged_compare2_pointer = compare2;
	compare_times = (size / STANDARD_SIZE);
	for (i = 0; i < compare_times; i++)
	{
		if (*(unsiged_compare1_pointer + i)
			!= *(unsiged_compare2_pointer + i))
			return false;
	}
	return true;
}

/**
 * @fn
 * find target from array
 * @param array array to search for
 * @param target what to look for
 * @param length number of elements in the array
 * @param size the size of the target data type
 * @return the element number where target is in array
 */
int
find_index(void *array, void *target,
				int length, uintptr_t size)
{
	int	i;

	for (i = 0; i < length; i++)
	{
	}
	return -1;
}
