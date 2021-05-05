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

void test(int filnum){\

    if( state[filnum] == GLOD && state[((filnum + 4)% 5)] != JEDZENIE && state[((filnum + 1)% 5)] != JEDZENIE){

        state[filnum] = JEDZENIE;

        sleep(2);

        printf("Filozof %d wzial widelec %d i widelec %d", filnum + 1, ((filnum + 4)% 5))+1, filnum + 1);

        printf("Filozof %d je", filnum + 1);

        sem_post(&fork[filnum]);

    }

}

void put_fork(int filnum){

    sem_wait(&mutex);

    state[filnum] = MYSLENIE;

    printf("Filozof %d odlozyl widelec %d i widelec %d", filnum + 1, ((filnum + 4)% 5))+1, filnum + 1);

    printf("Filozof %d mysli", filnum + 1);

    test(((filnum + 4)% 5)));
    test(((filnum + 1)% 5))v);

    sem_post(&mutex);

}

void take_fork(int filnum){

    sem_wait(&mutex);

    state [filnum] = GLOD;

    printf("Filozof %d jest glodny", filnum + 1);

    test(filnum);
    sem_post(&mutex);
    sem_wait(&fork[filnum]);

    sleep(1);

}

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
