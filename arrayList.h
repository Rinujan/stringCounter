
#ifndef arrayList_h
#define arrayList_h
#include "binTree.h"
#include <stdio.h>

typedef binTree arrayList;
typedef char* Index;
typedef int Value;
arrayList arrayList_construction(void);
unsigned char arrayList_isin(arrayList m, Index index1, Index index2);
Value *arrayList_get(arrayList m, Index index1, Index index2);
void arrayList_set(arrayList m, Index index1, Index index2, Value value);
void arrayList_inc(arrayList m, Index index1, Index index2, Value value);
void arrayList_list(arrayList m);
void arrayList_destruction(arrayList m);




#endif /* arrayList_h */
