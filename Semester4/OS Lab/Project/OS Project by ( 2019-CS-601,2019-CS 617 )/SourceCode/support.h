#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include "semaphore.h"

/***********
 * Defines
 ***********/
 
#define TRUE  1
#define FALSE 0

/* Bound for random sleep time before approaching the intersection */
#define TIME_TO_APPROACH 500000 //ms

/* Time to cross one portion of the intersection */
#define TIME_TO_CROSS 20000  //ms

/* Microsecond: 1 second = 1000000 usec */
#define TIME_USEC     1000000

/* Millisecond: 1 second = 1000 msec */
#define TIME_MSEC     1000


/***********
 * Structures
 ***********/
 
/* Type to encode the direction of a traveling car */
typedef enum 	//Works almost exactly as structure
{
    NORTH1 = 0,
    WEST   = 1,
    SOUTH1 = 2,
    EAST   = 3,
    DIRMAX = 4
} car_direction_t;

/* Type to encode possible states of the car */
typedef enum {
    STATE_WAITING_I1,     // Waiting on approach to intersection 1
    STATE_APPROACH_I1,    // Approaching intersection 1 (next to go from my direction)
    STATE_GO_LEFT_I1,     // Moving through intersection 1 to Left
    STATE_GO_RIGHT_I1,    // Moving through intersection 1 to Right
    STATE_GO_STRAIGHT_I1, // Moving through intersection 1 Straight
    STATE_LEAVE_I1,       // Leaving in the direction of final destination (from intersection 1)
    STATE_MAX
} car_state_t;

/* Location */
typedef enum {
    LOC_I1, // Intersection 1
    LOC_MAX
} car_location_t;

/* A general car structure to hold all of the state */
struct car_t {
    int car_id;	//ID will start from 0
    car_direction_t appr_dir;		//from where to start
    car_direction_t dest_dir;		//from where to end
    car_location_t  location;		//tells the location (quadrants)
    car_state_t     state;		//Car state or position
    struct timeval  start_time;	//At what time a car approches 
    struct timeval  end_time;		//At what time a car leaves
};
typedef struct car_t car_t;

/***********
 * Global Variables
 ***********/
/*
 * Lock to protect printf()
 */
semaphore_t support_print_lock;	//will work as a mutex lock to protect a semaphore to avoid deadlock


/***********
 * Function Declarations
 ***********/
 
/*
 * Initialize support library.
 *
 * Arguments:	None
 *   
 *
 * Returns:
 *   0 on success
 *  -1 on error
 */
 
int support_init(void);

/*
 * Finalize support library
 *
 * Arguments:	None
 *
 * Returns:
 *   0 on success
 *  -1 on error
 */
 
int support_finalize(void);

/*
 * Print a header to match output of print_state
 *
 * Arguments:	None
 *
 * Returns:
 *   Nothing
 */
 
void print_header(void);

/*
 * Print a footer to match output of print_state
 *
 * Arguments:	None
 *
 * Returns:
 *   Nothing
 */
 
void print_footer(void);

/*
 * Get a random direction of travel
 *
 * Arguments:
 *  exclude : A direction to exclude (negative if none) ==> jis taraf sy nikal raha hy.
 *
 * Returns:
 *  A random, valid direction.
 */
 
car_direction_t get_random_direction(car_direction_t exclude);

/*
 * Translate the direction as a two character string.
 *
 * Arguments:
 *  car_dir : Car direction of travel
 *
 * Returns:
 *  Two character representation of the direction or
 *  "Unknown" if not a valid direction.
 */
char * get_direction_as_string(car_direction_t car_dir);

/*
 * Translate the state into an approprate string
 *
 * Arguments:
 *  car_state : Car direction of travel
 *
 * Returns:
 *  String representation of the state or 
 *  "Unknown" if not a valid state.
 */
char * get_state_as_string(car_state_t car_state);

/*
 * Translate the location into an approprate string
 *
 * Arguments:
 *  car_loc : Car location
 *
 * Returns:
 *  String representation of the location or 
 *  "Unknown" if not a valid state.
 */
char * get_location_as_string(car_location_t car_loc);

/*
 * Print the state of the car.
 *
 * Arguments:
 *   this_car  = Car to display information about
 *   debug_str = Optional debugging string
 *
 * Returns:
 *   Nothing.
 */
void print_state(car_t this_car, char * debug_str);

/*
 * Convert 'struct timeval' to double representing time in milliseconds
 *
 * Arguments:
 *   ctime = Time structure to convert
 *
 * Returns:
 *   Time in milliseconds
 */
 
double timeval_to_double(struct timeval ctime);

/*
 * Take the difference between two timeval structures
 *
 * Arguments:
 *   start  = Start time (must be smaller than End time)
 *   end    = End time (must be larger than Start time)
 *
 * Returns:
 *   timeval structure containing the difference between the two times.
 */
struct timeval get_timeval_diff_as_timeval(struct timeval start, struct timeval end);

/*
 * Take the difference between two timeval structures
 *
 * Arguments:
 *   start  = Start time (must be smaller than End time)
 *   end    = Reference to End time (must be larger than Start time or NULL)
 *            If end == NULL, then the current gettimeofday() value will be used.
 *
 * Returns:
 *   Time in milliseconds
 */
double get_timeval_diff_as_double(struct timeval start, struct timeval *given_end);
