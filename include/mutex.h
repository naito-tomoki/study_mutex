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

#endif
