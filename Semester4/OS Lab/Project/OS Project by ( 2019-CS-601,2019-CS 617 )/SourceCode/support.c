#include "support.h"

static int initialized = FALSE;

int support_init(void) 
{
    int ret;
    unsigned int v=1;

    ret = semaphore_create(&support_print_lock,  v);
    initialized = TRUE;
 

    return ret;
}

int support_finalize(void) 
{
    int ret;

    ret = semaphore_destroy(&support_print_lock);
    initialized = FALSE;

    return ret;
}

void print_footer(void) 
{
    if(  initialized == FALSE )
     {
        
	printf("Warning: You forgot to call support_init() before calling print_footer()\n");        
	support_init();
    }

    printf("--------+---------------+------+--------------+--------------------------------\n");
}

void print_header(void) {
    if( initialized== FALSE )
     {

	printf("Warning: You forgot to call support_init() before calling print_header()\n");
        support_init();
    }

    printf("-------------------------------\n");
    printf("%7s | FROM to DEST  | Loc. | %12s | %s\n", "Car ID", "Time (msec)", "State");
    print_footer();
}

car_direction_t get_random_direction(car_direction_t exclude) 
{
    car_direction_t car_dir;
    do 
    {
        car_dir = random() % DIRMAX;
    } while(car_dir == exclude);

    return car_dir;
}

char * get_direction_as_string(car_direction_t car_dir) 
{
    switch(car_dir) 
    {
    case NORTH1:
        return strdup("N.");
    case WEST:
        return strdup("W.");
    case EAST:
        return strdup("E.");
    case SOUTH1:
        return strdup("S.");
    
    }

    return strdup("Unknown");
}

char * get_state_as_string(car_state_t car_state) 
{
    switch( car_state ) 
    {
    case STATE_WAITING_I1:
        return strdup("Waiting in line");
    case STATE_APPROACH_I1:
        return strdup("Next in line");
    case STATE_GO_LEFT_I1:
        return strdup("Turn Left");
    case STATE_GO_RIGHT_I1:
        return strdup("Turn Right");
    case STATE_GO_STRAIGHT_I1:
        return strdup("Go Straight");
    case STATE_LEAVE_I1:
        return strdup("Leave");
    
    }

    return strdup("Unknown");
}

char * get_location_as_string(car_location_t car_loc)
 {
    switch( car_loc ) 
    {
    case LOC_I1:
        return strdup(" 1 ");
    case LOC_MAX:
        return strdup("Max");
    }

    return strdup("Unknown");
}

void print_state(car_t this_car, char * debug_str) 
{
    char * appr_str = NULL;
    char * dest_str = NULL;
    char * loc_str = NULL;
    char * state_str = NULL;
    double timer;

    if( initialized == FALSE ) 
    {

	printf("Warning: You forgot to call support_init() before calling print_state()\n");
        support_init();
    }

    // Translate the direction
    appr_str  = get_direction_as_string( this_car.appr_dir );
    dest_str  = get_direction_as_string( this_car.dest_dir );
    loc_str   = get_location_as_string(  this_car.location );
    state_str = get_state_as_string(     this_car.state    );

    timer = get_timeval_diff_as_double(this_car.start_time, NULL);

    // Display the state
    semaphore_wait(&support_print_lock);

    if( debug_str == NULL ) 
    {
        printf("%7d | %4s to %-4s  | %4s | %12.3f | %-22s\n",this_car.car_id, appr_str, dest_str, loc_str, timer*TIME_MSEC, state_str);
    }
    else 
    {
        printf("%7d | %4s to %-4s  | %4s | %12.3f | %-22s | %s\n", this_car.car_id, appr_str, dest_str, loc_str, timer*TIME_MSEC, state_str, debug_str);
    }

    semaphore_post(&support_print_lock);

    // Cleanup the temporary strings
    free(appr_str);
    appr_str = NULL;

    free(dest_str);
    dest_str = NULL;

    free(loc_str);
    loc_str = NULL;

    free(state_str);
    state_str = NULL;

    return;
}

double timeval_to_double(struct timeval ctime) 
{
    if( initialized==FALSE )
     {
  
  	 printf("Warning: You forgot to call support_init() before calling timeval_to_double()\n");
	 support_init();
     }

    return (ctime.tv_sec + (ctime.tv_usec/(1.0 + TIME_USEC))); 
    
    //tv_sec ===>> The number of whole seconds elapsed since some starting point (for an elapsed time).
    //tv_usec ===>> The number of microseconds elapsed since the time given by the tv_sec member.
}

struct timeval get_timeval_diff_as_timeval(struct timeval start, struct timeval end) 
{
    struct timeval loc_diff;

    if( initialized == FALSE ) 
    {
        
        printf("Warning: You forgot to call support_init() before calling get_timeval_diff_as_timeval()\n");
        support_init();
    }

    /* Check to see if we have to carry a second over */
    
    if( end.tv_usec < start.tv_usec ) 
    {
        loc_diff.tv_usec = (TIME_USEC - start.tv_usec) + end.tv_usec;
       // end.tv_sec -= 1;
        
    } 
    else 
    {
        loc_diff.tv_usec = end.tv_usec - start.tv_usec;
    }

    loc_diff.tv_sec = end.tv_sec - start.tv_sec;

    return loc_diff;
}

double get_timeval_diff_as_double(struct timeval start, struct timeval *given_end) 
{
    struct timeval loc_diff, end;

    if(  initialized==FALSE  ) 
    {
	printf("Warning: You forgot to call support_init() before calling get_timeval_diff_as_double()\n");        
	support_init();
    }

    if( given_end ==NULL)
    {
        gettimeofday(&end, NULL);	//1st argument represents calender time ,  //2nd argument represents timezone
    } 
    
    else 
    {
        end.tv_sec  = given_end->tv_sec;
        end.tv_usec = given_end->tv_usec;
    }

    loc_diff = get_timeval_diff_as_timeval(start, end);

    return timeval_to_double(loc_diff);
}
