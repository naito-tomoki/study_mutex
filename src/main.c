#include <stdio.h>
#include "mutex.h"
#include "utils.h"

# define NUM_THREAD 1

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

	for (;is_share_loop(share);)
	{
		index = (share->array_index);
		value = 1;

		if (1 < index)
		{
			value =
				(share->array_numbers)[index - 1]
				+ (share->array_numbers)[index - 2];
		}

		share_input_value(share, value);

		puts("a");

	}
	return NULL;
}

bool
init_threads(t_share *share, pthread_t *thread)
{
	if (!share) return false;
	if (!thread) return false;

	return (create_thread(&thread[0], thread_fibo, share));
}

bool
end_threads(t_share *share, pthread_t *thread)
{
	if (!share) return false;
	if (!thread) return false;

	int	i;

	for (i = 0; i < NUM_THREAD; i++)
	{
		if (!join_thread(thread[i])) return false;
	}
	return true;
}

void
log_thread(t_share *share, pthread_t *thread)
{
	if (!share) return ;
	if (!thread) return ;


	for (; share->loop ;)
	{

		if (share->array_index > 100)
		{
			share_loop_change(share, false);
		}
	}
}

int
main(void)
{
	t_share		share;


	pthread_t	thread[NUM_THREAD];

	if (!share_init(&share)) return 1;

	if (!init_threads(&share, thread)) return 1;
	log_thread(&share, thread);
	if (!end_threads(&share, thread)) return 1;

	return 0;
}
