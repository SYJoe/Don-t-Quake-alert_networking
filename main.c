#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "header/network.h"
#include "header/alert.h"

#define PIN 28

int endOfSystem = 0;
int threadfinish1 = 999;
int threadfinish2 = 999;

int main()
{
    pthread_t thread_3;
    int return_thrd1;
    int return_thrd2;
    int return_EOS;

    pthread_create(&thread_1, NULL, detectModule, NULL);
    pthread_create(&thread_2, NULL, readToOtherSystem, NULL);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    blockModule();
    pthread_create(&thread_3, NULL, writeToOtherSystem, NULL);
    pthread_join(thread_3, NULL);
    pthread_create(&thread_1, NULL, main_lcd, NULL);
    return_EOS = main_buzzer();
    blockModule();
    return 0;
}