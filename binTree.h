
#ifndef binTree_h
#define binTree_h
#include "stringGen.h"
#include <stdio.h>
typedef struct binTree_node {
    Key key;
    Data data;
    struct binTree_node *left, *right;
} binTree_node;
typedef binTree_node** binTree;
binTree binTree_ini(void);
void binTree_insert(binTree bst, Key key, Data data);
binTree_node *new_node(Key key, Data data);
Data binTree_search(binTree bst, Key key);
void binTree_traversal(binTree bst);
//helper function
void binTree_traversalnode(binTree_node *node);
void binTree_free(binTree bst);

#endif
