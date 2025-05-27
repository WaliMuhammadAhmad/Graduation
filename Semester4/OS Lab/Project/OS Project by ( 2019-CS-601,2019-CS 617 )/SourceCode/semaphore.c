#include "semaphore.h"

/*
 * Broad permissions for the semaphore
 */
#define S_ALL (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)


int semaphore_create(semaphore_t *sem, int value)
{
    /* Initialize the variables */
    sem->sem  = NULL;
    sem->name = NULL;

if (USE_NAMED_SEMAPHORES == 0)
{
     
    if(  sem->name==NULL  ) 
    {
        printf("Error: semaphore_create(): Failed to allocate memory for the name\n");
        return -1;
    }
    

    printf("Creating a semaphore named: %s\n", sem->name); 

    sem->sem = sem_open(sem->name, O_CREAT|O_EXCL, S_ALL, value);
    if( SEM_FAILED == sem->sem ) 
    {
        perror("Error: sem_open failed!");
        printf("Failed on Semaphore named %s\n", sem->name);
        return -2;
    }

    return 0;
}
else
{
    printf("Creating a semaphore named: UNNAMED (value %d)\n", value); 
    sem->sem = (sem_t*)malloc(sizeof(sem_t) * 1);
    if( sem->sem ==NULL  ) 
    {
        printf("Error: semaphore_create(): Failed to allocate memory for the semaphore\n");
        return -1;
    }

    return sem_init(sem->sem, 0 , value); //0 is the value of flag
}
}


int semaphore_destroy(semaphore_t *sem)
{
    int rtn;

if (USE_NAMED_SEMAPHORES == 0)
{
    rtn = sem_close(sem->sem);
    if( rtn != 0 ) 
    {
        printf("Error: semaphore_destroy(): sem_close failed with %d (skip sem_unlink)\n", rtn);
    } 
    else 
    {
        rtn = sem_unlink(sem->name);
    }
}
else
{
    rtn = sem_destroy(sem->sem);

    if(  sem->sem != NULL ) 
    {
        free(sem->sem); 	//Id value will be freed 
        sem->sem = NULL;
    }
}


    if( sem->name != NULL ) 
    {
        free(sem->name);
        sem->name = NULL;
    }
    sem->sem  = NULL;

    return rtn;
}


int semaphore_wait(semaphore_t *sem)
{
    int ret;

    /*
     * Condition checks
     */
     
    if( sem == NULL  ) 
    {
        printf("Error: semaphore_wait(): Invalid argument!\n");
        return -2;
    }

    if(  sem->sem == NULL ) 
    {
        printf("Error: semaphore_wait(): Semaphore has not been created yet!\n");
        return -3;
    }

    usleep(0); // Just to keep you wait for microseconds
    
    ret = sem_wait(sem->sem);
    return ret;
}


int semaphore_post(semaphore_t *sem)
{
    int ret;

    /*
     * COndition checks
     */
     
    if( sem  == NULL  ) 
    {
        printf("Error: semaphore_post(): Invalid argument!\n");
        return -2;
    }

    if( sem->sem == NULL ) 
    {
        printf("Error: semaphore_post(): Semaphore has not been created yet!\n");
        return -3;
    }

    ret = sem_post(sem->sem);
    usleep(0); // Just to keep you waiting.
    return ret;
}


int semaphore_trywait(semaphore_t *sem)
{
    /*
     * Sanity checks
     */
    if( sem == NULL) 
    {
        printf("Error: semaphore_trywait(): Invalid argument!\n");
        return -2;
    }

    if(  sem->sem == NULL ) 
    {
        printf("Error: semaphore_trywait(): Semaphore has not been created yet!\n");
        return -3;
    }

    return sem_trywait(sem->sem);
}
