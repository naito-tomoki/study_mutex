#ifndef MUTEX_H
# define MUTEX_H

# include <pthread.h>
# include <stdbool.h>
# include <errno.h>

# define NUM_THREADS 5
# define ARRAY_SIZE 1000

typedef struct s_share
{
	pthread_mutex_t	mutex;
	int				array_numbers[ARRAY_SIZE];
	int				array_index;
	bool			loop;
}	t_share;

/* init functions */
bool
mutex_init(pthread_mutex_t *mutex);

bool
share_init(t_share *share);

/* mutex functions */
bool
mutex_lock(t_share *share);

bool
mutex_unlock(t_share *share);

/* thread functions */
bool
create_thread(pthread_t *thread,
	void *(routine_function)(void *), void *arg);

bool
join_thread(pthread_t thread);

/* operate share value */
bool
share_input_value(t_share *share, int value);

bool
share_loop_change(t_share *share, bool is_loop);

bool
is_share_loop(t_share *share);

#endif
