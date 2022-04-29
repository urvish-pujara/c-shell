#include "headers.h"
#include "pwd.h"
void pwd(){
    char a[100];
    getcwd(a,100);
    printf("%s\n",a);
}