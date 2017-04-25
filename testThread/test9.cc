#include <pthread.h>
#include <stdio.h>
#include <chrono>
void* thrd_start_routine(void* v)
{
    int i;
    
    for (i = 0; i < 10; i++)
    {
		std::chrono::seconds(1);
        printf("child thread sleep 1 seconds, i = %d\n", i);
    }
}

int main()
{
    pthread_t thrdid;
                
    pthread_create(&thrdid, NULL, &thrd_start_routine, NULL);
        
    int i;
    
    for (i = 0; i < 5; i++)
    {
        printf("main thread sleep 1 seconds, i = %d\n", i);
        std::chrono::seconds(1);
    }
    
    pthread_exit(NULL);//此处若调用，则下面的printf就不会输出。

    printf("main thread befor return\n");
    return  0;
}

