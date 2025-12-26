#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>

/**
 * @fn
 * print error message for red font color
 * @param msg error message string
 * @return is print correctly
 */
int
print_error(const char *msg, ...);

/**
 * @fn
 * compare 2 variables value to check same value
 * @param compare1 one of the compare variable
 * @param compare2 compare with compare1 variable
 * @param size the size of the 2 variables data type
 * @return is compare 2 variables are same value
 */
bool
is_same(const void *compare1, const void *compare2,
			const uintptr_t size);

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
				const int length, const uintptr_t size);

#endif
