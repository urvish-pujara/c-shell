#include "headers.h"
#include "cd.h"


void cd(char a[],char home_dir[],char prev_dir[]) {
    int space=0,i,j=0;
    char f[100]={'\0'};
    
    for(i=0;i<strlen(a);i++){
        if(a[i]==' ' || a[i]=='\t'){
            if(a[i+1]!=' ' && a[i+1]!='\t' && a[i+1]!='\n'){
                space++;
            }
            if(space>1){
                //printf("%d\n",space);
                printf("cd: too many arguments\n");
                return;
            }
        }
    }
    //printf("%d\n",space);
    if (a[3]=='~'){
        chdir(home_dir);
        return;
    }
    if (a[3]=='-'){
        chdir(prev_dir);
        return;
    }
    i=3;
    j=0;
    while(a[i]!='\n'){
        f[j]=a[i];
        j++;
        i++;
    }
    if(chdir(f)<0){
        printf("cd: %s: No such file or directory\n",f);
    }
    else{
        chdir(f);
    }
}
/*
int main(){
    char a[100]="cd",b[100],d[100];
    getcwd(b,100);
    printf("%s\n",b);
    cd(a,"/home/ubuntu","/home/ubuntu/Music");
    getcwd(d,100);
    printf("%s\n",d);
}*/