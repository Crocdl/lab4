//
// Created by дмитрий on 25.04.2023.
//
#include "a_function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *readstring(FILE *f) {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n;
    do {
        n = fscanf(f, "%80[^\n]", buf);
        if (n < 0) {
            return NULL;
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}
int w_add(KeySpace **head){
    int key, value, er;
    er = fscanf(stdin, "%d", &key);
    fscanf(stdin, "%*c");
    er = fscanf(stdin, "%d", &value);
    if (er < 0){
        return -1;
    }
    er = add(head, key, value);
    return er;
}
int w_find_elem(KeySpace *elem){
    int key;
    fscanf(stdin, "%d", &key);
    KeySpace *find =find_elem(elem, key);
    if (find == NULL){
        return -3;
    }
    find = creat_elem(find->key, find -> item ->value);
    fprintf(stdout, "key %d -- %d\n", find->key, find->item->value);
    free(find -> item);
    free(find);
    return 0;
}

int w_delete(KeySpace **head){
    int key, er;
    er = fscanf(stdin, "%d", &key);
    if (er < 0){
        return -1;
    }
    er = delete(head, key);
    return er;
}
int w_getf(KeySpace **tree){
    char *file = readstring(stdin);
    if (file == NULL){
        free(file);
        return -1;
    }
    FILE *f = fopen(file, "r");
    free(file);
    if (f == NULL){
        perror(NULL);
        return -1;
    }
    int er = getf(tree, f);
    fclose(f);
    if (er < 0){
        return er;
    }
    return 0;
}
int w_dprinttree(KeySpace *tree){
    char *file = readstring(stdin);
    if (file == NULL){
        free(file);
        return -1;
    }
    FILE *f = fopen(file, "w+");
    free(file);
    if (f == NULL){
        perror(NULL);
        return -2;
    }
    fprintf(f, "digraph HelloWorld {");
    dprinttree(tree, f);
    fprintf(f, "}");
    fclose(f);
    return 0;
}
int w_output(KeySpace *tree){
    int key, key1;
    int er = fscanf(stdin, "%d", &key);
    fscanf(stdin, "%*c");
    er = fscanf(stdin, "%d", &key1);
    fscanf(stdin, "%*c");
    if (er < 0){
        return -1;
    }
    output(tree, key, key1);
    return 0;
}
int w_find_min(KeySpace *tree){
    KeySpace *find =find_min(tree);
    if (find == NULL){
        return -3;
    }
    find = creat_elem(find->key, find -> item ->value);
    fprintf(stdout, "key %d -- %d\n", find->key, find->item->value);
    free(find -> item);
    free(find);
    return 0;
}