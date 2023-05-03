//
// Created by дмитрий on 21.04.2023.
//

#ifndef LAB4_A_FUNCTION_H
#define LAB4_A_FUNCTION_H
//
// Created by дмитрий on 20.04.2023.
//
#include "struct.h"
#include <stdio.h>
KeySpace *find_min(const KeySpace *elem);
KeySpace *find_max(const KeySpace *elem);
KeySpace *find_prev(KeySpace* elem);
KeySpace *find_next(KeySpace* elem);
KeySpace *creat_elem(int key, int value);
int add(KeySpace **head, int key, int value);
int output(KeySpace *elem, int key, int key2);
KeySpace *find_elem(KeySpace *elem, int key);
int delete(KeySpace **head, int key);
void end(KeySpace **tree);
int getf(KeySpace **tree, FILE *f);
void printtree (KeySpace *tree, int n);
void dprinttree (KeySpace *tree, FILE *f);
void diterPreorder(KeySpace *tree, FILE *f);
void iterPreorder(KeySpace *tree);
#endif //LAB4_A_FUNCTION_H
