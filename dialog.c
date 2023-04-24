//
// Created by дмитрий on 21.04.2023.
//
#include "a_function.h"
#include <stdio.h>
int main() {
    KeySpace *tree = NULL;
    int er = add(&tree, 5, 1);
    er = add(&tree, 3, 2);
    er = add(&tree, 1, 3);
    er = add(&tree, 4, 3);
    er = add(&tree, 7, 4);
    er = add(&tree, 11, 5);
    er = output(tree);
    er = delete(&tree, 4);
    er = output(tree);
    return 0;
}