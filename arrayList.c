
#include "arrayList.h"
//initiallizing arrayList by calling binTree_ini
arrayList arrayList_construction(void){
    arrayList bst= binTree_ini();
    return bst;
}
//checking if the key is in arrayList
unsigned char arrayList_isin(arrayList m, Index index1, Index index2){
    unsigned char isfree='0';
    //creating new key and data
    Key newindex=stringGen(index1, index2);
    Data newdata=binTree_search(m, newindex);
    //return 1 if new data is found
    if(newdata!=NULL){
        isfree='1';
        return isfree;
    }
    else
        //if not return 0
        return isfree;
    
}
//get a data with a key in arrayList
Value *arrayList_get(arrayList m, Index index1, Index index2){
    //create the new key and data
    Key newindex=stringGen(index1, index2);
    //binTree_search will either return the data or null so we return this
    Data newdata=binTree_search(m, newindex);

    return newdata;
}
//setting a arrayList node
void arrayList_set(arrayList m, Index index1, Index index2, Value value){
    //creaing a new key and data
    Key newindex=stringGen(index1, index2);
    Data newdata=NULL;
    //if data is found that means we already have a node there and we can just change the existing data
    newdata = binTree_search(m, newindex);
    if(newdata!=NULL){
    intSet(newdata, value);
    }
    //if not we have to insert the node with the generated key and data
    else{
        binTree_insert(m, newindex, intGen(value));
    }
}
void arrayList_inc(arrayList m, Index index1, Index index2, Value value){
    Key newindex=stringGen(index1, index2);
    Data newdata=binTree_search(m, newindex);
    //incrementing the data with the new value
    if(newdata!=NULL){
        int newvalue=*newdata+value;
        //the modifie the data with the new data
        intSet(newdata,newvalue);
    }
    else
        //or error message is printed
        printf("Error!Location is not defined within the arrayList");
}
void arrayList_list(arrayList m){
    //calls binTree traversal
    binTree_traversal(m);
}
void arrayList_destruction(arrayList m){
    //frees the memory allocated for the arrayList
    binTree_free(m);
}






