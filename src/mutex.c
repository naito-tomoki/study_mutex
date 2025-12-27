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

bool
mutex_lock(t_share *share)
{
	if (!share) return false;

	pthread_mutex_t *mutex =
						&(share->mutex);

	const int	error =
		pthread_mutex_lock(mutex);
	switch (error)
	{
		case EINVAL:
		case EDEADLK:
			return false;
		default:
			;
	}
	return true;
}

bool
mutex_unlock(t_share *share)
{
	if (!share) return false;

	pthread_mutex_t	*mutex =
						&(share->mutex);

	const int	error =
		pthread_mutex_lock(mutex);
	switch (error)
	{
		case EINVAL:
		case EPERM:
			return false;
		default:
			;
	}
	return true;
}

bool
share_thread(pthread_t *thread,
	void *(routine_function)(void *), void *arg)
{
	const int	error =
		pthread_create(thread, NULL, routine_function, arg);
	switch (error)
	{
		case EAGAIN:
		case EINVAL:
		case EPERM:
			return false;
		default:
			;
	}
	return true;
}

bool
share_input_value(t_share *share, int value)
{
	if (!share) return false;

	if (!mutex_lock(share)) return false;
	(share->array_numbers)[share->array_index] = value;
	(share->array_index)++;
	if (!mutex_unlock(share)) return false;
	return true;
}
