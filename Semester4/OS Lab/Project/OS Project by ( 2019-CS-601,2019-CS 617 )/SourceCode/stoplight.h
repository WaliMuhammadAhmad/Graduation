#include "support.h"
#include <float.h>

/***********
 * Structures
 ***********/
 
struct node
{
  void *data;
  struct node *next;
};

typedef struct node node;

struct queue
{
    int sizeOfQueue;
    size_t memSize;
    node *head;
    node *tail;
};

typedef struct queue queue;

/***********
 * Global Variables
 ***********/
/*
 * Time to live (Seconds)
 */
 
int ttl = 0;

/*
 * Number of cars (threads) in the system
 */
int num_cars = 0;

/*
 * Indicate when for threads to stop processing and exit
 */
int time_to_exit = FALSE;

/*
 * Numbers representing collected statistscs
 */
 double count = 0;
 double min = DBL_MAX;
 double max = -1;
 double total = 0;
 
 
/*
 * Queue of Cars
 */
 queue car_q;

/*
 * Array keeping track of whether or not cars are coming from each direction
 */
 int isOpen[] = {1, 1, 1, 1};
 
/*
 * Semaphores
 */
semaphore_t northWest;
semaphore_t northEast;
semaphore_t southEast;
semaphore_t southWest;
semaphore_t queueMutex;
semaphore_t isOpenMutex;
semaphore_t conditionSignal;
semaphore_t statisticMutex;
semaphore_t printStuff;



/***********
 * Function Declarations
 ***********/
/*
 * Pass command line arguments
 */
int pass_args(int argc, char **argv);

/*
 * Main thread function that picks an arbitrary direction to approach from,
 * and to travel to for each car.
 *
 * Arguments:
 *   param = The car ID number for printing purposes
 *
 * Returns:
 *   NULL
 */
 
void *start_car(void *param);

/*
  Destroying the semapohers
*/

int destroy_semaphores();

/*
  Creates the semaphores
*/

int create_semaphores();

/*
int cancelthreads removes the threads by joining, to make a complete process
*/

int cancelThreads(pthread_t *threads, int size);

/*

*/

void printSafe(char * str, int id);


/*
 * QUEUE CODE
 * -----------------------------------------------------------------------------------------------------------------------------------------------
 */
 
void queueInit(queue *q, size_t memSize);
int enqueue(queue *, const void *);
void dequeue(queue *, void *);
void queuePeek(queue *, void *);
void clearQueue(queue *);
int getQueueSize(queue *);
