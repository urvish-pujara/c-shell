#include "headers.h"
#include "repeat.h"

int repeat2(char b[]){
    int a= b[7]-'0';
    int c= b[8]-'0';
    int d;
    if(a>9 || a<0){
        printf("Number not found\n");
    }
    if(c<=9 && c>=0){
        d= (10*a) +c;
    }
    else {
        d=a;
    }
    return d;
}
char * repeat(char b[]){
    int a= b[7]-'0';
    int c= b[8]-'0';
    int d;
    char *g;
    if(a>9 || a<0){
        printf("Number not found\n");
    }
    if(c<=9 && c>=0){
        d= (10*a) +c;
    }
    else {
        d=a;
    }
    if(d==a){
        g=&b[9];
    }
    else{
        g = &b[10];
    }
    return g;
}
/*
int main(){
    char a[100]="repeat 89 echo hello\n";
    repeat(a);
}*/