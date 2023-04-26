//
// Created by дмитрий on 26.04.2023.
//
#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *f = fopen("statistick", "w+");
    perror(NULL);
    int r, len;
    len = 500;
    fprintf(f, "%d\n", len);
    for (int i = 0; i< len; i++){
        fprintf(f, "%d\n", rand()%1000);
        fprintf(f, "%d\n", rand()%1000);
    }
    return 0;
}