#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define MYSLENIE 2
#define GLOD 1
#define JEDZENIE 0

int state[5];
int fil[5] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t fork[5];



void* filozof(void* num){

    while (1){
        int* i = num;
        sleep(1);
        take_fork(*i);
        sleep(0);
        put_fork(*i);
    }

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
