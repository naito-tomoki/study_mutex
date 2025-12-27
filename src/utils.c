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
 * find target from array
 * @param array array to search for
 * @param target what to look for
 * @param length number of elements in the array
 * @param size the size of the target data type
 * @return the element number where target is in array
 */
int
find_index(const void *array, const void *target,
				const int length, const uintptr_t size)
{
	int							i;
	const unsigned char			*unsigned_array;
	const unsigned char			*unsigned_target;

	unsigned_array = (const unsigned char *)array;
	unsigned_target = (const unsigned char *)target;
	for (i = 0; i < length; i++)
	{
		if (memcmp(unsigned_array + (i * size), unsigned_target, size) == 0)
			return i;
	}
	return -1;
}
