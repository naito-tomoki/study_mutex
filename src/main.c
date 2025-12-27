#include <stdio.h>
#include "mutex.h"
#include "utils.h"

int
main(void)
{
	t_share	share;

	if (!share_init(&share)) return 1;

	int	array[] = {1, 5, 10, 100};
	int	target = 10;
	int	res = find_index(array, &target,
		sizeof(array) / sizeof(array[0]), sizeof(int));
	printf("index: %d\n", res);
	return 0;
}
