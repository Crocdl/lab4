//
// Created by дмитрий on 26.04.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "a_function.h"
#include <time.h>
#include <unistd.h>
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
int main(){
    srand(time(NULL));
    int len;
    len = 10000;
    KeySpace *tree = NULL;
    struct timespec mt1, mt2;
    //Переменная для расчета дельты времени
    long int tt;
    int r = 0;
    for (int j = 0; j< len; j++) {
        add(&tree, rand(), rand());
        if (j % 100 == 0) {

            //Определяем текущее время
            clock_gettime (CLOCK_REALTIME, &mt1);

            r += add(&tree, rand(), rand());
//            int *aaaaaa = (int*) malloc(sizeof (int)*4);

            //Определяем текущее время
            clock_gettime (CLOCK_REALTIME, &mt2);
//            aaaaaa[0] = 1;
//            free(aaaaaa);
            //Рассчитываем разницу времени между двумя измерениями
            tt=(mt2.tv_nsec - mt1.tv_nsec);

            //Выводим результат расчета на экран
            printf("Затрачено время: %ld нс\n",tt);

        }
    }
    printf("%d\n", r);
    end(&tree);
//    printtree(tree, 0);
    return 0;
}