

#include <stdio.h>
#include "arrayList.h"

int main(int argc, const char * argv[]) {
    //creating and initializing new arrayList object
    arrayList newarrayList;
    newarrayList = arrayList_construction();
    //creating 2 strings for the input pairs
    char newchar[200];
    char newchar2[200];
    int numofoccurance=1;
    //finding out how many pair of strings the user wants to enter
    printf("how many lines of string pairs do you wish to enter. Please enter a integer\n");
    int count;
    int i=1;
    scanf("%d",&count);
    
    //keep looping for the number of times the user inputted
    while (count>0){
        printf("please enter line : %d\n",i);
        //the key is scanned
    scanf(" %s %s",newchar,newchar2);
        unsigned char isfree=arrayList_isin(newarrayList, newchar, newchar2);
        //if the key already exists then we just increase the occurance by one.
        if(isfree=='1')
            arrayList_inc(newarrayList, newchar, newchar2, numofoccurance);
        else
            //if not we have to create a new node with a new key and data
        arrayList_set(newarrayList, newchar, newchar2, numofoccurance);
        
        count--;
        i++;
    }
    if(*newarrayList!=NULL){
    printf("String 1  String 2  Occurence\n");
    //printing the tree
    arrayList_list(newarrayList);
    //free all dynamically allocated memory
    arrayList_destruction(newarrayList);
    }
}
