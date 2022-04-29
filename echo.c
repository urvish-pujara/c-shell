#include "headers.h"
#include "echo.h"

void echo(char a[]) {
    int i=5;
    while(a[i]!='\n'){
        if(a[i]==' ' || a[i]=='\t'){
            if(a[i+1]!=' ' && a[i+1]!='\t' && a[i+1]!='\n'){
                printf("%c",a[i]);    
            }
        }
        else{
            printf("%c",a[i]);
        }
        i++;
    }
    printf("\n");
}