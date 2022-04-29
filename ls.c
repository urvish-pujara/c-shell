#include "headers.h"
#include "ls.h"
void file_char(mode_t mode){
    char t;
    if(S_ISREG(mode)){
        t = '-';
    }
    else if(S_ISDIR(mode)){
        t = 'd';
    }
    else{
        t = '?';
    }
    printf("%c",t);
}
void per(mode_t mode){
    char rwx[8][3] = {"---","--x","-w-","r--","rw-","-wx","r-x","rwx"};
    char ans[10]={'\0'};
    
    strcpy(&ans[0], rwx[7]);
    strcpy(&ans[3], rwx[7]);
    strcpy(&ans[6], rwx[7]);
    if(mode & S_ISUID){
        if(mode & S_IXUSR){
            ans[2] = 's';
        }
        else{
            ans[2] = 'S';
        }
    }
    if(mode & S_ISGID){
        if(mode & S_IXGRP){
            ans[5] = 's';
        }
        else{
            ans[5] = 'l';
        }
    }
    if(mode & S_ISVTX){
        if(mode & S_IXOTH){
            ans[8] = 't';
        }
        else{
            ans[8] = 'T';
        }
    }
    printf("%s",ans);
    printf(" ");
    //printf("%s ",ans);;
}

void file_details(struct stat *file_pe){
    char date[20];
    file_char(file_pe->st_mode);
    per(file_pe->st_mode);
    printf("%ld ",file_pe->st_nlink);
    printf("%s ",getpwuid(file_pe->st_uid)->pw_name);
    printf("%s ",getgrgid(file_pe->st_gid)->gr_name);
    printf("%ld ",file_pe->st_size);
    strftime(date,20,"%b %d %H:%M",localtime(&(file_pe->st_ctime)));
    printf("%s ",date);
}
void file_stat_store(char path[],char file[]){
    char file_path[100];
    strcpy(file_path,path);
    strcat(file_path,"/");
    strcat(file_path,file);
    struct stat file_per;
    lstat(file_path,&file_per);
    file_details(&file_per);
}
void ls(char str[]){
    DIR *d;
    struct dirent *dir;
    d = opendir(str);
    if(d){
        while((dir = readdir(d))!= NULL){
            printf("%s\n",dir->d_name);
        }
        closedir(d);
    }
}

void ls3(char str[]){
    //printf("aaaaaaaa\n");
    DIR *d;
    struct dirent *dir;
    d = opendir(str);
    if(d){
        char path[100]={'\0'};
        if (str[0]=='/'){
            strcpy(path,str);
        }
        else{
            getcwd(path,100);
            strcat(path,"/");
            strcat(path,str);
        }
        while((dir = readdir(d))!= NULL){
            char name[100]={'\0'};
            strcpy(name,dir->d_name);
            if(name[0]!='.'){
                file_stat_store(path,name);
                printf("%s\n",name);
            }
        }
        closedir(d);
    }
}
void ls2(char str[]){
    DIR *d;
    struct dirent *dir;
    d = opendir(str);
    if(d){
        while((dir = readdir(d))!= NULL){
            char name[100]={'\0'};
            strcpy(name,dir->d_name);
            if(name[0]!='.'){
                printf("%s\n",name);
            }
        }
        closedir(d);
    }
}
void ls4(char str[]){
    DIR *d;
    struct dirent *dir;
    d = opendir(str);
    if(d){
        char path[100]={'\0'};
        if (str[0]=='/'){
            strcpy(path,str);
        }
        else{
            getcwd(path,100);
            strcat(path,"/");
            strcat(path,str);
        }
        while((dir = readdir(d))!= NULL){
            char name[100]={'\0'};
            strcpy(name,dir->d_name);
            file_stat_store(path,name);
            printf("%s\n",name);
        }
        closedir(d);
    }
}
void get(char a[]){
    char str[100];
    int i,j;

    //1
    if (strcmp("ls\n",a)==0){
        //printf("djnvj\n");
        strcpy(str,".");
        ls2(str);
    }
    //2
    else if(strcmp("ls .\n",a)==0){
        strcpy(str,".");
        ls2(str);
    }
    //3
    else if(strcmp("ls ..\n",a)==0){
        strcpy(str,"..");
        ls2(str);
    }
    //4
    else if(strcmp("ls -a\n",a)==0){
        strcpy(str,".");
        ls(str);
    }
    //5
    else if(strcmp("ls -l\n",a)==0){
        //printf("aaaaaaaa\n");
        strcpy(str,".");
        ls3(str);
    }
    //6
    else if(strcmp("ls -al\n",a)==0 || strcmp("ls -a -l\n",a)==0 || strcmp("ls -l -a\n",a)==0 ||strcmp("ls -l -a\n",a)==0){
        strcpy(str,".");
        ls4(str);
    }
    //7
    else if(a[3]!='-'){
        int fd=strlen(a);
        j=0;
        for(i=3;i<(fd-1);i++){
            str[j]=a[i];
            j++;
        }
        int gf= strlen(str);
        char real_str[100]={'\0'};
        for(i=0;i<(gf-1);i++){
            real_str[i]=str[i];
        }
        ls2(real_str);
    }
    //8
    else if(a[3]=='-' && a[4]=='l' && a[5]==' ' && a[6]=='-' && a[7]=='a' && a[8]==' '){
        for(i=9,j=0;i<strlen(a)-1;i++,j++){
            str[j]=a[i];
        }
        ls4(str);
    }
    //9
    else if(a[3]=='-' && a[4]=='a' && a[5]==' ' && a[6]=='-' && a[7]=='l' && a[8]==' '){
        int fd=strlen(a);
        j=0;
        for(i=9;i<(fd-1);i++){
            str[j]=a[i];
            j++;
        }
        int gf= strlen(str);
        char real_str[100]={'\0'};
        for(i=0;i<(gf-1);i++){
            real_str[i]=str[i];
        }
        ls4(real_str);
    }
    //10
    else if(a[3]=='-' && a[4]=='a' && a[5]==' '){
        int fd=strlen(a);
        j=0;
        for(i=6;i<(fd-1);i++){
            str[j]=a[i];
            j++;
        }
        int gf= strlen(str);
        char real_str[100]={'\0'};
        for(i=0;i<(gf-1);i++){
            real_str[i]=str[i];
        }
        ls(real_str);
    }
    //11
    else if(a[3]=='-' && a[4]=='l' && a[5]==' '){
        int fd=strlen(a);
        j=0;
        for(i=6;i<(fd-1);i++){
            str[j]=a[i];
            j++;
        }
        int gf= strlen(str);
        char real_str[100]={'\0'};
        for(i=0;i<(gf-1);i++){
            real_str[i]=str[i];
        }
        ls3(real_str);
    }
    //12
    else if(a[3]=='-' && a[4]=='l' && a[5]=='a'){
        int fd=strlen(a);
        j=0;
        for(i=7;i<(fd-1);i++){
            str[j]=a[i];
            j++;
        }
        int gf= strlen(str);
        char real_str[100]={'\0'};
        for(i=0;i<(gf-1);i++){
            real_str[i]=str[i];
        }
        ls4(real_str);
    }
    //13
    else if(a[3]=='-' && a[4]=='a' && a[5]=='l'){
        int fd=strlen(a);
        j=0;
        for(i=7;i<(fd-1);i++){
            str[j]=a[i];
            j++;
        }
        int gf= strlen(str);
        char real_str[100]={'\0'};
        for(i=4;i<(gf-1);i++){
            real_str[i]=str[i];
        }
        ls2(real_str);
    }
    else{
        ls2(".");
    }
}
/*
int main(){
    char a[100]="ls\n";
    get(a);
}*/