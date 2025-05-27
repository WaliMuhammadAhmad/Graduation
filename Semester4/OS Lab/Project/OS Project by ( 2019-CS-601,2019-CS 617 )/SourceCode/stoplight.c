#include "stoplight.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]) 
{
    int ret;
    int i;
    
    if (argc<3)
    {
    	printf("Argument Missing...\n");
    	exit(0);
    }
    else if( argc>3)
    {
	printf("Argument values Exceed...\n");
	exit(0);
    }
    /*
     * Pass Command Line arguments
     */
     ret = pass_args(argc, argv);
     
    if( ret != 0) 
    {
        return -1;
    }

    /*
     * Initialize:
     * - random number generator
     * - queue
     */
     
    srand(time(NULL));
    queueInit(&car_q, sizeof(car_t));
    
    if(  create_semaphores()!= 0 )
    {
	printf("Error: Creating semaphores failed.");
	return -1;
    }
    
    /*
     * Create Car Thread(s)
     * 
     */
     
    pthread_t carThreads[num_cars];

    for(i = 0; i < num_cars; ++i) 
    {
        if( pthread_create(&carThreads[i],NULL,start_car,(void*)(intptr_t)i)!=0) //intptr_t ==>> signed integer memsize-type that can safely 											    //store a pointer regardless of the platform capacity.
        {
            
		printf("Error: Cannot Create thread\n");
		exit(-1);
        }
        
    }
    

    /*
     * Wait for the TTL to expire
     */
     
    // sleep specified amount of time
    // set time_to_exit to TRUE

    print_header();
    sleep(ttl);
    time_to_exit = 1;
    
    cancelThreads(carThreads, num_cars);

    /*
     * Print timing information
     */
     
    print_footer();
    printf("Min.  Time:\t%f\n", min);
    printf("Avg.  Time:\t%f\n", total/count);
    printf("Max.  Time:\t%f\n", max);
    printf("Total Time:\t%f\n", total);
    print_footer();


    /*
     * Cleanup
     * 
     */
     
    if( destroy_semaphores() !=0 )
    {
    
	printf("Error: Destroying semaphores failed.");
	return -1;
    }

    /*
     * Finalize support library
     */
     
    support_finalize();

    return 0;
}



int pass_args(int argc, char **argv)
{
    /*
     * Initialize support library
     */
    support_init();
  
    if(argc == 3)
    {
        //checking that all values are > 0
        if (atoi(argv[1]) > 0)
        {
          
          ttl = atoi(argv[1]);
        }
        else 
        {
          exit(-1);
        }
        
        if (atoi(argv[2]) > 0)
        {
          num_cars = atoi(argv[2]);
        }
        else 
        {
	  printf("INVALID VALUES...\n");
          exit(-1);
        }
        
    }
    
    else
    {
        exit(-1);
    }

    return 0;
}

/*
 * Approach intersection
 * param = Car Number (car_id)
 */

void *start_car(void *param) 
{
    int car_id = (intptr_t)param;   //intptr_t ===>> signed integer memsize-type, safely store a pointer regardless of the platform capacity.
    car_t this_car;
    this_car.car_id = car_id;
    
    
   // Section for car set up was already in while loop, 
   //it can be updated at the beginning of each loop instead of before, and at the end.


    /*
     * Keep cycling through
     */
     
    while( time_to_exit == FALSE ) 
    {
        double time = 0;

        /*
         * Sleep for a bounded random amount of time before approaching the
         * intersection
         */
         
        usleep(random()%TIME_TO_APPROACH);
        
        /*
         * Setup the car's direction, where it is headed, set its state
         */
         
        this_car.appr_dir = get_random_direction(-1);
        this_car.dest_dir = get_random_direction(this_car.appr_dir);
        this_car.state = STATE_WAITING_I1;
        this_car.location = LOC_I1;
        
        /*
         * Mark start time for car
         */
         
        gettimeofday(&this_car.start_time, NULL);
        gettimeofday(&this_car.end_time, NULL);
        print_state(this_car, NULL);
        
        //Only allow one thread to access the queue at a time
        semaphore_wait(&queueMutex);
        
            //printSafe("Car: %d is being enqueued\n", this_car.car_id);
            enqueue(&car_q, &this_car);
            
            //printSafe("Car: %d is enqueued\n", this_car.car_id);
        semaphore_post(&queueMutex);
        
        while(1){
            semaphore_wait(&queueMutex);
                car_t endCarPtr;
                //printSafe("Car: %d is being looked at\n", this_car.car_id);
                queuePeek(&car_q, &endCarPtr);
                //printSafe("the first car in the queue is %d\n", endCarPtr.car_id);
            semaphore_post(&queueMutex);
            
            semaphore_wait(&conditionSignal);//t1
                //if the current car's id is the one at the end of the queue.
                semaphore_wait(&isOpenMutex);
                if(this_car.car_id == endCarPtr.car_id && isOpen[this_car.appr_dir] == 1){
                    //pop the car off the queue and set the isOpen spot to false.
                    semaphore_wait(&queueMutex);
                        
                        dequeue(&car_q, &endCarPtr);
                        
                    semaphore_post(&queueMutex);
                    isOpen[this_car.appr_dir] = 0;
                    this_car.state = STATE_APPROACH_I1;
                    print_state(this_car,NULL);
                        
                    semaphore_post(&isOpenMutex);
                    semaphore_post(&conditionSignal);
                    break;
                }
                else
                {
                    //send in the next thread to be checked.
                    semaphore_post(&isOpenMutex);
                    semaphore_post(&conditionSignal);
                }
        }
        
        //INTERSECTION LOGIC
        // we are using the numbers as its easier to remember what position
        // the number represents rather than remember the direction names
        /*
        sem_post
        
        DESCRIPTION       
       sem_post() increments (unlocks) the semaphore pointed to by sem.  If
       the semaphore's value consequently becomes greater than zero, then
       another process or thread blocked in a sem_wait() call will be woken
       up and proceed to lock the semaphore.
        RETURN VALUE

       sem_post() returns 0 on success; on error, the value of the semaphore
       is left unchanged, -1 is returned, and errno is set to indicate the
       error.
        
        
        */
        
         /*
         * Move the car in the direction and change its state accordingly
         */
         
        int canExit = 0;
        
        while(!canExit)
        {
            switch(this_car.appr_dir)
            {
                case 0: // North
                switch(this_car.dest_dir)
                {
                    case 1: // West right turn
                        this_car.state = STATE_GO_RIGHT_I1;
                        if(semaphore_trywait(&northWest) == 0)
                        {
                            canExit =1;
                            semaphore_wait(&isOpenMutex);
                                isOpen[this_car.appr_dir] = 1;
                            semaphore_post(&isOpenMutex);
                            print_state(this_car, NULL);
                            //wait
                            usleep(TIME_TO_CROSS);
                            //release semaphores in order
                            semaphore_post(&northWest);
                            
                        }
                    break;
                    case 2: // South straight
                        this_car.state = STATE_GO_STRAIGHT_I1;
                        if(semaphore_trywait(&northWest) == 0){
                            if(semaphore_trywait(&southWest) == 0){
                                canExit =1;
                                semaphore_wait(&isOpenMutex);
                                    isOpen[this_car.appr_dir] = 1;
                                semaphore_post(&isOpenMutex);
                                print_state(this_car, NULL);
                                //wait
                                usleep(TIME_TO_CROSS);
                                //release semaphores in order
                                semaphore_post(&northWest);
                                usleep(TIME_TO_CROSS);
                                semaphore_post(&southWest);
                            }else{
                                //need to back out.
                                semaphore_post(&northWest);
                            }
                        }
                    break;
                    case 3: // East left turn
                        this_car.state = STATE_GO_LEFT_I1;
                        if(semaphore_trywait(&northWest) == 0){
                            if(semaphore_trywait(&southWest) == 0){
                                if(semaphore_trywait(&southEast) == 0){
                                    canExit =1;
                                    semaphore_wait(&isOpenMutex);
                                        isOpen[this_car.appr_dir] = 1;
                                    semaphore_post(&isOpenMutex);
                                    print_state(this_car, NULL);
                                    //wait
                                    usleep(TIME_TO_CROSS);
                                    //release semaphores in order
                                    semaphore_post(&northWest);
                                    usleep(TIME_TO_CROSS);
                                    semaphore_post(&southWest);
                                    usleep(TIME_TO_CROSS);
                                    semaphore_post(&southEast);
                                }else{
                                    //need to back out.
                                    semaphore_post(&southWest);
                                    semaphore_post(&northWest);
                                }
                            }
                            else{
                                //need to back out.
                                semaphore_post(&northWest);
                            }
                        }
                    break;
                    default:
                    printf("THIS SHOULD NEVER HAPPEN unless the direction was set to something it shouldnt have been.\n");
                    break;
                }
                break;
                
                case 1: // West
                switch(this_car.dest_dir)
                {
                    case 0: // North left
                        this_car.state = STATE_GO_LEFT_I1;
                        if(semaphore_trywait(&southWest) == 0){
                            if(semaphore_trywait(&southEast) == 0){
                                if(semaphore_trywait(&northEast) == 0){
                                    canExit =1;
                                    semaphore_wait(&isOpenMutex);
                                        isOpen[this_car.appr_dir] = 1;
                                    semaphore_post(&isOpenMutex);
                                    print_state(this_car, NULL);
                                    //wait
                                    usleep(TIME_TO_CROSS);
                                    //release semaphores in order
                                    semaphore_post(&southWest);
                                    usleep(TIME_TO_CROSS);
                                    semaphore_post(&southEast);
                                    usleep(TIME_TO_CROSS);
                                    semaphore_post(&northEast);
                                }else{
                                    //need to back out.
                                    semaphore_post(&southEast);
                                    semaphore_post(&southWest);
                                }
                            }
                            else{
                                //need to back out.
                                semaphore_post(&southWest);
                            }
                        }
                        
                    break;
                    case 2: // South right
                        this_car.state = STATE_GO_RIGHT_I1;
                        if(semaphore_trywait(&southWest) == 0){
                            canExit =1;
                            semaphore_wait(&isOpenMutex);
                                isOpen[this_car.appr_dir] = 1;
                            semaphore_post(&isOpenMutex);
                            print_state(this_car, NULL);
                            //wait
                            usleep(TIME_TO_CROSS);
                            //release semaphores in order
                            semaphore_post(&southWest);

                        }
                    break;
                    case 3: // East stright
                        this_car.state = STATE_GO_STRAIGHT_I1;
                        if(semaphore_trywait(&southWest) == 0){
                            if(semaphore_trywait(&southEast) == 0){
                                canExit =1;
                                semaphore_wait(&isOpenMutex);
                                    isOpen[this_car.appr_dir] = 1;
                                semaphore_post(&isOpenMutex);
                                print_state(this_car, NULL);
                                //wait
                                //release semaphores in order
                                usleep(TIME_TO_CROSS);
                                semaphore_post(&southWest);
                                usleep(TIME_TO_CROSS);
                                semaphore_post(&southEast);
                            }else{
                                //need to back out.
                                semaphore_post(&southWest);
                            }
                        }
                    break;
                    default:
                    printf("THIS SHOULD NEVER HAPPEN unless the direction was set to something it shouldnt have been.\n");
                    break;
                }break;
                
                case 2: // South
                switch(this_car.dest_dir){
                    case 0: // North straight
                        this_car.state = STATE_GO_STRAIGHT_I1;
                        if(semaphore_trywait(&southEast) == 0){
                            if(semaphore_trywait(&northEast) == 0){
                                canExit =1;
                                semaphore_wait(&isOpenMutex);
                                    isOpen[this_car.appr_dir] = 1;
                                semaphore_post(&isOpenMutex);
                                print_state(this_car, NULL);
                                //wait
                                //release semaphores in order
                                usleep(TIME_TO_CROSS);
                                semaphore_post(&southEast);
                                usleep(TIME_TO_CROSS);
                                semaphore_post(&northEast);
                            }else{
                                //need to back out.
                                semaphore_post(&southEast);
                            }
                        }
                    break;
                    case 1: // West left
                        this_car.state = STATE_GO_LEFT_I1;
                        if(semaphore_trywait(&southEast) == 0){
                            if(semaphore_trywait(&northEast) == 0){
                                if(semaphore_trywait(&northWest) == 0){
                                    canExit =1;
                                    semaphore_wait(&isOpenMutex);
                                        isOpen[this_car.appr_dir] = 1;
                                    semaphore_post(&isOpenMutex);
                                    print_state(this_car, NULL);
                                    //wait
                                    //release semaphores in order
                                    usleep(TIME_TO_CROSS);
                                    semaphore_post(&southEast);
                                    usleep(TIME_TO_CROSS);
                                    semaphore_post(&northEast);
                                    usleep(TIME_TO_CROSS);
                                    semaphore_post(&northWest);
                                }else{
                                    //need to back out.
                                semaphore_post(&northEast);
                                semaphore_post(&southEast);
                                }
                            }
                            else{
                                //need to back out.
                                semaphore_post(&southEast);
                            }
                        }
                    break;
                    case 3: // East right
                        this_car.state = STATE_GO_RIGHT_I1;
                        if(semaphore_trywait(&southEast) == 0){
                            canExit =1;
                            semaphore_wait(&isOpenMutex);
                                isOpen[this_car.appr_dir] = 1;
                            semaphore_post(&isOpenMutex);
                            print_state(this_car, NULL);
                            //wait
                            //release semaphores in order
                            usleep(TIME_TO_CROSS);
                            semaphore_post(&southEast);

                        }
                    break;
                    default:
                    printf("THIS SHOULD NEVER HAPPEN unless the direction was set to something it shouldnt have been.\n");
                    break;
                }break;
                
                case 3: // East
                switch(this_car.dest_dir){
                    case 0: // North right
                        this_car.state = STATE_GO_RIGHT_I1;
                        if(semaphore_trywait(&northEast) == 0){
                            canExit =1;
                            semaphore_wait(&isOpenMutex);
                                isOpen[this_car.appr_dir] = 1;
                            semaphore_post(&isOpenMutex);
                            print_state(this_car, NULL);
                            //wait
                            //release semaphores in order
                            usleep(TIME_TO_CROSS);
                            semaphore_post(&northEast);
                        }
                    break;
                    case 1: // West straight
                        this_car.state = STATE_GO_STRAIGHT_I1;
                        if(semaphore_trywait(&northEast) == 0){
                            if(semaphore_trywait(&northWest) == 0){
                                canExit =1;
                                semaphore_wait(&isOpenMutex);
                                    isOpen[this_car.appr_dir] = 1;
                                semaphore_post(&isOpenMutex);
                                print_state(this_car, NULL);
                                //wait
                                //release semaphores in order
                                usleep(TIME_TO_CROSS);
                                semaphore_post(&northEast);
                                usleep(TIME_TO_CROSS);
                                semaphore_post(&northWest);
                            }else{
                                //need to back out.
                                semaphore_post(&northEast);
                            }
                        }
                    break;
                    case 2: // South left
                        this_car.state = STATE_GO_LEFT_I1;
                        if(semaphore_trywait(&northEast) == 0){
                            if(semaphore_trywait(&northWest) == 0){
                                if(semaphore_trywait(&southWest) == 0){
                                    canExit =1;
                                    semaphore_wait(&isOpenMutex);
                                        isOpen[this_car.appr_dir] = 1;
                                    semaphore_post(&isOpenMutex);
                                    print_state(this_car, NULL);
                                    //wait
                                    //release semaphores in order
                                    usleep(TIME_TO_CROSS);
                                    semaphore_post(&northEast);
                                    usleep(TIME_TO_CROSS);
                                    semaphore_post(&northWest);
                                    usleep(TIME_TO_CROSS);
                                    semaphore_post(&southWest);
                                    
                                }else{
                                    //need to back out.
                                semaphore_post(&northWest);
                                semaphore_post(&northEast);
                                }
                            }
                            else{
                                //need to back out.
                                semaphore_post(&northEast);
                            }
                        }
                    break;
                    default:
                    printf("THIS SHOULD NEVER HAPPEN unless the direction was set to something it shouldnt have been.\n");
                    break;
                }break;
                default:
                printf("THIS SHOULD NEVER HAPPEN");
                break;
            }
        }
        // the car has gone through the intersection, and released its resources.
        // set to leaving and print once more
        this_car.state = STATE_LEAVE_I1;
        print_state(this_car, NULL);
        /*
         * Mark leave time for car
         */

        gettimeofday(&this_car.end_time, NULL);
        time = TIME_MSEC * get_timeval_diff_as_double(this_car.start_time, NULL);
        /*
         * Save statistics about the cars travel
         */
        semaphore_wait(&statisticMutex);
            count++;
            if(time < min) min = time; 
            if(time > max) max = time;
            total+=time;
        semaphore_post(&statisticMutex);


    }

    /*
     * All done
     */
    pthread_exit((void *) 0);

    return NULL;
}


int create_semaphores()
{
    int ret;

    
    // each of these numbered sempahores represents a position of the intersection. 
    //zero is the top left hand quadrant and moves clockwise. 
    if( (ret = semaphore_create(&northWest,1))!=0   ) {
//      fprintf(stderr, "Error: semaphore_create() failed with %d\n", ret);
	printf("Error: semaphore_create() failed with %d\n", ret);
    return -1;
    }
    if(  (ret = semaphore_create(&northEast,1)) !=0 )
     {

	printf("Error: semaphore_create() failed with %d\n", ret);      
	return -1;
    }
    if( (ret = semaphore_create(&southEast,1)) !=0 ) 
    {

	printf("Error: semaphore_create() failed with %d\n", ret);

      return -1;
    }
    if(  (ret = semaphore_create(&southWest,1)) !=0 )
     {
    
	printf("Error: semaphore_create() failed with %d\n", ret);      
	return -1;
    }
    if( (ret = semaphore_create(&isOpenMutex,1)) !=0 ) {

	printf("Error: semaphore_create() failed with %d\n", ret);      
	return -1;
    }
    if( (ret = semaphore_create(&queueMutex,1)) !=0) 
    {
 
	printf("Error: semaphore_create() failed with %d\n", ret);   
   	return -1;
    }
    if(  (ret = semaphore_create(&conditionSignal,1)) !=0 )
     {
	printf("Error: semaphore_create() failed with %d\n", ret);  
    	return -1;
    }
    if(  (ret = semaphore_create(&printStuff,1)) !=0 ) {

	printf("Error: semaphore_create() failed with %d\n", ret);  
    	return -1;
    }
    if(  (ret = semaphore_create(&statisticMutex,1)) !=0 )
     {

	printf("Error: semaphore_create() failed with %d\n", ret);  
    	return -1;
    }
    return 0;
}



int destroy_semaphores(){
    int ret;
    if(  (ret = semaphore_destroy(&northWest)) !=0) 
    {
    
	printf("Error: semaphore_destroy() failed with %d\n", ret);
        return -1;
    }
    if(  (ret = semaphore_destroy(&northEast)) !=0)
     {
    
	printf("Error: semaphore_destroy() failed with %d\n", ret);        
	return -1;
    }
    if(  (ret = semaphore_destroy(&southEast)) !=0) 
    {

   
	printf("Error: semaphore_destroy() failed with %d\n", ret);
     	return -1;
    }
    if( (ret = semaphore_destroy(&southWest)) !=0) {
       
      printf("Error: semaphore_destroy() failed with %d\n", ret);
 	return -1;
    }
     if( (ret = semaphore_destroy(&isOpenMutex)) !=0) 
     {
	printf("Error: semaphore_destroy() failed with %d\n", ret);        
	return -1;
    }
     if( (ret = semaphore_destroy(&queueMutex))!=0 ) 
     {
 
	printf("Error: semaphore_destroy() failed with %d\n", ret);   
     	return -1;
    }
    if(  (ret = semaphore_destroy(&conditionSignal))!=0 )
     {
 
	printf("Error: semaphore_destroy() failed with %d\n", ret);   
     	return -1;
    }
    if( (ret = semaphore_destroy(&printStuff)) !=0) 
    {
 	printf("Error: semaphore_destroy() failed with %d\n", ret);   
     	return -1;
    }
     if( (ret = semaphore_destroy(&statisticMutex)) !=0) 
     {
	printf("Error: semaphore_destroy() failed with %d\n", ret);  
      	return -1;
    }
    return 0;
}

int cancelThreads(pthread_t *threads, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        pthread_cancel(threads[i]);
    }
    return 0;
}


/*
 * QUEUE CODE
 * -----------------------------------------------------------------------------------------------------------------------------------------------
 */

 void queueInit(queue *q, size_t memSize)
{
   q->sizeOfQueue = 0;
   q->memSize = memSize;
   q->head = q->tail = NULL;
}

int enqueue(queue *q, const void *data)
{
    node *newNode = (node *)malloc(sizeof(node));

    if(newNode == NULL)
    {
        return -1;
    }

    newNode->data = malloc(q->memSize);

    if(newNode->data == NULL)
    {
        free(newNode);
        return -1;
    }

    newNode->next = NULL;

    memcpy(newNode->data, data, q->memSize);

    if(q->sizeOfQueue == 0)
    {
        q->head = q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }

    q->sizeOfQueue++;
    return 0;
}

void dequeue(queue *q, void *data)
{
    if(q->sizeOfQueue > 0)
    {
        node *temp = q->head;
        memcpy(data, temp->data, q->memSize);

        if(q->sizeOfQueue > 1)
        {
            q->head = q->head->next;
        }
        else
        {
            q->head = NULL;
            q->tail = NULL;
        }

        q->sizeOfQueue--;
        free(temp->data);
        free(temp);
    }
}

void queuePeek(queue *q, void *data)
{
    if(q->sizeOfQueue > 0)
    {
       node *temp = q->head;
       memcpy(data, temp->data, q->memSize);
    }
}

void clearQueue(queue *q)
{
  node *temp;

  while(q->sizeOfQueue > 0)
  {
      temp = q->head;
      q->head = temp->next;
      free(temp->data);
      free(temp);
      q->sizeOfQueue--;
  }

  q->head = q->tail = NULL;
}

int getQueueSize(queue *q)
{
    return q->sizeOfQueue;
}

void printSafe(char * str, int id){
    semaphore_wait(&printStuff);
    printf(str, id);
    semaphore_post(&printStuff);
}
