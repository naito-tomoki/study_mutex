#include <stdio.h>
#include "mutex.h"
#include "utils.h"

int
main(void)
{
	t_share	share;

	if (!share_init(&share)) return 1;

	int	value1 = 0xFFF;
	int	value2 = 0xFFF + 0;

	printf("is_same: %d\n", is_same(&value1, &value2, sizeof(int)));
	return 0;
}
