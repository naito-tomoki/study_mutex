#include <stdio.h>
#include "mutex.h"
#include "utils.h"

int
main(void)
{
	t_share	share;

	if (!share_init(&share)) return 1;

	print_error("nothing to done %s", "...");
	return 0;
}
