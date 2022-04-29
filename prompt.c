#include "headers.h"
#include "prompt.h"

void prompt(char home_dir[100]) {
    char a[100],b[100],path_n[100]={'\0'},path[100];
    int c,home=1,i;
    getlogin_r(a,100);
    c = gethostname(b,100);
    int e = strlen(home_dir);
    getcwd(path,100);
    for(int i=0;i<e;i++){
        if(home_dir[i]!=path[i]){
            home =0;
            break;
        }
    }
    if (home==0){
        strcpy(path_n,path);
    }
    if(home==1){
        path_n[0]='~';
        int ky=strlen(path);
        for(i=e;i<ky;i++){
            path_n[i+1-e]=path[i];
        }
    }
    printf("<%s@%s:%s>",a,b,path_n);
}