#include <stdio.h>
#include <stdlib.h> /* For malloc */
#include <errno.h>
#include <unistd.h> /* For usleep = The function usleep() is a C API that suspends the current process for the number of microseconds passed to it. It can be used for delaying a job.*/
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include<sys/types.h>

#define USE_NAMED_SEMAPHORES 1



/*
 * Semaphore type
 */

struct semaphore_t {
    sem_t *sem;
    char *name;
};
typedef struct semaphore_t semaphore_t;

/*
 * Create a POSIX Semaphore
 *
 * Parameters:
 *   sem : semaphore to create (pass-by-reference)
 *   value : initial value of the semaphore
 *
 * Returns:
 *   0 upon success,
 *   and non-0 if there was an error.
 */
int semaphore_create(semaphore_t *sem, int value);


/*
 * Destroy a POSIX Semaphore
 *
 * Parameters:
 *  sem : semaphore to destroy (pass-by-reference)
 *
 * Returns:
 *   0 upon success,
 *   and non-0 if there was an error.
 */
int semaphore_destroy(semaphore_t *sem);


/*
 * Wait on a POSIX Semaphore
 *
 * Parameters:
 *   sem : semaphore to wait on (pass-by-reference)
 *
 * Returns:
 *   0 upon success,
 *   and non-0 if there was an error.
 */
int semaphore_wait(semaphore_t *sem);


/*
 * Signal a POSIX Semaphore
 *
 * Parameters:
 *   sem : semaphore to signal (pass-by-reference)
 *
 * Returns:
 *   0 upon success,
 *   and non-0 if there was an error.and it is in waiting queue
 */
int semaphore_post(semaphore_t *sem);// sem =signal


/*
 * Try to Wait on a POSIX Semaphore
 *
 * Parameters:
 *   sem : semaphore to wait on (pass-by-reference)
 *
 * Returns:
 *   0 if the lock was acquired.
 *  -1 if the lock was not acquired
 *   other non-0 if there was an error.
 */
int semaphore_trywait(semaphore_t *sem);
 /* SEM_SUPPORT */
