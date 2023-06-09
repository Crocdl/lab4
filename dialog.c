//
// Created by дмитрий on 11.04.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "wraper.h"
#include "a_function.h"
#include <time.h>
void errore(int er){
    switch (er){
        case 3: fprintf(stdout, "\nERRORE of function's index"); break;
        case 0: fprintf(stdout, "\nOK\n"); break;
        case 1: fprintf(stdout, "\nOK2\n"); break;
        case -2: fprintf(stdout, "\nERRORE of something\n"); break;
        case -1: fprintf(stdout, "\nERRORE of tamsthing\n"); break;
        case -4: fprintf(stdout, "\nERRORE of -4\n"); break;
        case -6: fprintf(stdout, "\nERRORE of 3\n"); break;
        default: fprintf(stdout, "\nERRORE of anything\n"); break;
    }
}
void dialog(){
    KeySpace *tree = NULL;
    int er = 0;
    int flag = 1;
    int ifunc = 1;
    clock_t start, stop;
    while (flag){

        printf("\n0 - end\n1 - add\n2 - find elem\n3 - delete\n4 - output\n5 - getf\n 6 - printTree\n 7 - grafviz\n");
        er = fscanf(stdin, "%d", &ifunc);
        fscanf(stdin, "%*c");
        if (er >  0 && ifunc >= 0 && ifunc < 9){
            start = clock();
            switch (ifunc) {
                case 0: flag = 0; break;
                case 1: er = w_add(&tree); break;
                case 2: er = w_find_elem(tree); break;
                case 3: er = w_delete(&tree); break;
                case 4: er = w_output(tree); break;
                case 5: er = w_getf(&tree); break;
                case 6: iterPreorder(tree);  break;
                case 7: w_dprinttree(tree); break;
                case 8: er = w_find_min(tree); break;
                default: er = -10;
            }
        }else er = 3;
        stop = clock();
        errore(er);
        printf("%lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
    }
    end(&tree);
}