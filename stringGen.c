
#include "stringGen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//duplicate a string and return the pointer
char * stringRepeat(char *str){
    
    char *duplicate;
    int k;
    duplicate=(char*)malloc((strlen(str)+1)*sizeof(char));
    for(k=0;k<=strlen(str);k++){
        duplicate[k]=str[k];
    }
    return duplicate;
   
}
//generating new key with dynamically allocated memory
Key stringGen(char *skey1, char *skey2){
    Key newkey;
    newkey=(Key)malloc(sizeof(Key));
    //using duplicate function so that the string lateral is accounted for
    newkey->skey1=stringRepeat(skey1);
    newkey->skey2=stringRepeat(skey2);
    return newkey;
}
//comparing keys to see where it going in the binary search tree
int stringComp(Key key1, Key key2){
    int num;
    num= strcmp(key1->skey1, key2->skey1);
    if (num==0){
        int num2=strcmp(key1->skey2, key2->skey2);
        return num2;
    }
    else
        return num;
}
//printing key
void stringPrint(Key key){
    printf("  %s ,   %s ",key->skey1,key->skey2);
}
//free memory of the key
void stringFree(Key key){
    free(key);
}
//creating data object by dynamically allocating it memory and setting the data to a integer passed in.
Data intGen(int idata){
    Data newdata;
    newdata= (Data)malloc(sizeof(Data));
    //Data object must be dereferenced first so that we get the value and not the addresses
    *newdata= idata;
    return newdata;
}
//setting the data if a data object already exists in memory
void intSet(Data data, int idata){
    //Data object must be dereferenced first so that we get the value and not the addresses
    *data=idata;
}
//printing the data
void intPrint(Data data){
    printf("         %d\n ",*data);
}
//freeing the allocating memory for data
void intFree(Data data){
    free(data);
}







