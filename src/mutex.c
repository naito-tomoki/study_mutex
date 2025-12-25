#include "mutex.h"
#include <string.h>

bool
mutex_init(pthread_mutex_t *mutex)
{
	if (!mutex) return false;

	const int	error =
		pthread_mutex_init(mutex, NULL);
	switch (error)
	{
		case EINVAL:
		case ENOMEM:
		case EAGAIN:
			return false;
		default:
			;
	}
	return true;
}

bool
share_init(t_share *share)
{
	if (!share) return false;

	if (!mutex_init(&(share->mutex))) return false;
	bzero(share->array_numbers, sizeof(int) * ARRAY_SIZE);
	share->array_index = 0;
	return true;
}
