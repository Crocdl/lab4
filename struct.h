//
// Created by дмитрий on 20.04.2023.
//

#ifndef LAB4_STRUCT_H
#define LAB4_STRUCT_H
typedef struct Item{
    int value;
}Item;
typedef struct KeySpace{
    int key;
    struct KeySpace *left, *right, *firm, *perent;
    struct Item *item;
}KeySpace;
#endif //LAB4_STRUCT_H
