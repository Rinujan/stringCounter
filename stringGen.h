
#ifndef stringGen_h
#define stringGen_h

#include <stdio.h>

typedef int* Data;
typedef struct {char *skey1; char *skey2;} Key_struct;
typedef Key_struct* Key;
char * stringRepeat(char *str);
Key stringGen(char *skey1, char *skey2);
int stringComp(Key key1, Key key2);
void stringPrint(Key key);
void stringFree(Key key);
Data intGen(int idata);
void intSet(Data data, int idata);
void intPrint(Data data);
void intFree(Data data);

#endif 
