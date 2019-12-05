
#include "binTree.h"
#include <stdlib.h>
//initionalizing the tree by allocating memory and setting to null.
binTree binTree_ini(void){
    binTree bst;
    bst = (binTree) malloc( sizeof(binTree_node*));
    *bst = NULL;
    return bst;
}
//inserting a new node into the binary search tree with its associated key and data
void binTree_insert(binTree bst, Key key, Data data){
    //inserting the first node which is the root node.
    if(*bst==NULL){
        *bst=new_node(key, data);
    }
    else{
        //getting the rootnode from *bst and naming it newtempnode
   binTree_node *newtempnode;
   newtempnode=*bst;
        //loop keeps going till we insert a node or node already exists or we are out of bounds.
        while(newtempnode->data!=NULL){
            //if the key in the tree is bigger then the one we are trying to enter we move to the left child
            if(stringComp(newtempnode->key, key)>0){
                //if the left child is empty we can insert
                if(newtempnode->left->data==NULL){
                    newtempnode->left=new_node(key, data);
                    break;
                }
                //if not we move to the left child and continue the loop
                else{
                    newtempnode=newtempnode->left;
                }
            }
            //if the key in the tree is smaller then the one we are trying to insert we move to the right child
            else if(stringComp(newtempnode->key, key)<0){
                //if right child is empty we can insert
                if(newtempnode->right->data==NULL){
                newtempnode->right=new_node(key, data);
                break;
                }
            
            else
                //if not we move to the right child and continue with the loop
                newtempnode=newtempnode->right;
            }
            //if the node already exists we break the loop and dont need to do anything further
            else
                break;
        }
        }
    }
    
//helper function to create a brand new node
binTree_node *new_node(Key key, Data data){
    //allocating memory for new node and its children
    binTree_node *tempnode= (binTree_node*)(malloc(sizeof(binTree_node)));
    tempnode->left=(binTree_node*)malloc(sizeof(binTree_node));
    tempnode->right=(binTree_node*)malloc(sizeof(binTree_node));
    //children dont have any data yet
    tempnode->left->data=tempnode->right->data=NULL;
    //new node had data and key
    tempnode->data= data;
    tempnode->key=key;
    //no grandchildren
    tempnode->left->left=tempnode->left->right=NULL;
    tempnode->right->left=tempnode->right->right=NULL;
    return tempnode;
}
Data binTree_search(binTree bst, Key key){
    binTree_node *tempnode=*bst;
    //we go into the loop as long as the tree is not empty
    if(tempnode!=NULL){
        //we loop the whole tree
    while (tempnode->data!=NULL){
        //if the key in the tree is bigger then the one we are trying to enter we move to the left child
        if(stringComp(tempnode->key, key)>0){
            tempnode=tempnode->left;
        }
        else if(stringComp(tempnode->key, key)<0){
            tempnode=tempnode->right;
        }
        else {
            //if key comp is 0 means that we have found the node with the specified key
            return tempnode->data;
        }
    }
    }
    //return null if no node is found with the key
    return NULL;
}
//this function passes in the tree for traversal however for i have made another traversal function that passes in the rootnode of the given tree for my convenience
void binTree_traversal(binTree bst){
   
    binTree_node *tempnode1=*bst;
    binTree_traversalnode(tempnode1);
}
//helper function
  void binTree_traversalnode(binTree_node *node){
      //if we are at a leaf we go back up
    if (node->data==NULL){
        return;
    }
      //for inorder traversal we start at the leaf and print its key and data then go to the right child. then we move to the parent and move up. this keeps going till we get to the root.
    binTree_traversalnode(node->left);
    stringPrint(node->key);
    intPrint(node->data);
    binTree_traversalnode(node->right);
    
}
//2 free functions to free all memory associated with binary search tree
//helper function
static void btree_free(binTree_node *bt){
    //if we are at a leaf go back up
    if ( bt == NULL )
        return;
    //free the left child then right then key and data then the entire node
    btree_free(bt->left);
    btree_free(bt->right);
    free(bt->key);
    free(bt->data);
    free(bt);
}
void binTree_free(binTree bst){
    //recursively free all nodes then the entire tree
    btree_free(*bst);
    free(bst);
}



