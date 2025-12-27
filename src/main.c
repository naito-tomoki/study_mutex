#include <stdio.h>
#include "mutex.h"
#include "utils.h"

/**
 * @param arg t_share structure
 */
void *
thread_increment(void *arg)
{
	if (!arg) return NULL;

	t_share	*share;

	share = (t_share *)arg;
	return NULL;
}

/**
 * @param arg t_share structure
 */
void *
thread_fibo(void *arg)
{
	if (!arg) return NULL;

	t_share	*share;
	int		index;
	int		value;

	share = (t_share *)arg;
	index = (share->array_index);
	value = 1;

	if (1 < index)
	{
		value =
			(share->array_numbers)[index - 1]
			+ (share->array_numbers)[index - 2];
	}

	share_input_value(share, value);

	return NULL;
}

bool
create_thread(t_share *share)
{
	int	i;
return true;
}

void
log_thread(t_share *share)
{
return true;
}

int
main(void)
{
	t_share	share;

	if (!share_init(&share)) return 1;

	if (!create_thread(&share)) return 1;
	log_thread(&share);
	if (!join_thread(&share)) return 1;

	return 0;
}
