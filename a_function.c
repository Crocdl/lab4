//
// Created by дмитрий on 20.04.2023.
//
#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
KeySpace *find_min(KeySpace *elem){
    KeySpace *iter = elem;
    while(iter->left != NULL){
        iter = iter -> left;
    }
    return iter;
}
KeySpace *find_max(KeySpace *elem){
    KeySpace *iter = elem;
    while(iter->right != NULL){
        iter = iter -> right;
    }
    return iter;
}
KeySpace *find_prev(KeySpace* elem){
    if (elem->left != NULL){
        return find_max(elem);
    }else{
        KeySpace *iter = elem -> perent;
        KeySpace *iter2 = elem;
        while (iter != NULL && iter -> left == iter2){
            iter2 = iter;
            iter = iter -> perent;
        }
        return iter;
    }
}
KeySpace *find_next(KeySpace* elem){
    if (elem->right != NULL){
        return find_min(elem->right);
    }else{
        KeySpace *iter = elem -> perent;
        KeySpace *iter2 = elem;
        while (iter != NULL && iter -> right == iter2){
            iter2 = iter;
            iter = iter -> perent;
        }
        return iter;
    }
}
KeySpace *creat_elem(int key, int value){
    KeySpace *elem = (KeySpace *)malloc(sizeof(KeySpace));
    Item *info = (Item *)malloc(sizeof(Item));
    info -> value = value;
    elem -> right = NULL;
    elem -> left = NULL;
    elem -> perent = NULL;
    elem -> firm = NULL;
    elem -> item = info;
    elem -> key = key;
    return elem;
}
int add(KeySpace **head, int key, int value){

    if (*head == NULL){
        *head = creat_elem(key, value);
        return 0;
    }else{
        KeySpace *iter = *head;
        KeySpace *buff;
        while (iter != NULL){
            buff = iter;
            if (iter -> key == key ){
                return -1;
            }
            if (iter -> key > key ){
                iter = iter -> left;
            }else{
                iter = iter -> right;
            }
        }
        if (buff -> key > key){
            iter = creat_elem(key, value);
            buff -> left = iter;
            iter -> perent = buff;
        }else {
            iter = creat_elem(key, value);
            buff->right = iter;
            iter->perent = buff;
        }
        buff = find_next(iter);
        if (buff == NULL){
            iter -> firm  = find_prev(iter);
            return 0;
        }
        iter -> firm = buff -> firm;
        buff -> firm = iter;
        return 0;
    }
}
int output(KeySpace *tree){
    KeySpace *iter = find_max(tree);
    while (iter != NULL){
        printf("%d  %d\n", iter -> key, iter -> item -> value);
        iter = iter -> firm;
    }
    printf("\n");
    return 0;
}
KeySpace *find_elem(KeySpace *elem, int key){
    while (elem != NULL){
        if (elem -> key == key){
            return elem;
        }
        if (elem -> key > key){
            elem = elem -> left;
        }else{
            elem = elem -> right;
        }
    }
    return NULL;
}
int delete(KeySpace **head, int key){
    if (*head == NULL){
        return -1;
    }
    KeySpace *elem = find_elem(*head, key);
    if (elem == NULL){
        return -1;
    }
//    y - перносимый, р - его дерево, parent - его родитель
    KeySpace *y, *p, *parent;
    if (elem->left == NULL || elem -> right == NULL){
        y = elem;
    }else{
        y = find_next(elem);
    }
    if (y -> left != NULL){
        p = y -> left;
    }else{
        p = y -> right;
    }
    parent = y->perent;
    if (p != NULL){
        p->perent = parent;
    }
    if (parent == NULL){
        *head = p;
    }
    if (parent -> left == y){
        parent -> left = p;
    }else{
        parent -> right = p;
    }
    if (y != elem) {
        elem->key = y->key;
        elem->item = y->item;
        KeySpace *next = find_next(elem);
        next -> firm = elem;
        free(y);
    }
    else {
    	        KeySpace *next = find_next(y);
    	        next -> firm = y -> firm;
    }
    return 0;
}

