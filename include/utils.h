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
is_same(void *compare1, void *compare2, uintptr_t size);

#endif
