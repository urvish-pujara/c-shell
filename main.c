#include "prompt.h"
#include "headers.h"
#include "echo.h"
#include "pwd.h"
#include "cd.h"
#include "ls.h"
#include "repeat.h"

char home_dir[100]={'\0'};
char prev_dir[100]={'\0'};
char history[20][100]={'\0'};
int com_no = 0;
int fill = 0;
char *commands[100];
char *token[100];
int i=0;
int j=0;
void display(){
    if(fill==1){
        for(i=0;i<10;i++){
            printf("%s\n",history[(com_no+i)%20]);
        }
    }
    if(fill==0){
        for(i=0;i<=com_no;i++){
            printf("%s\n",history[i]);
        }
    }
}
void displayn(int n){
    if(fill==1){
        for(i=0;i<n;i++){
            printf("%s\n",history[(com_no+i)%20]);
        }
    }
    if(fill==0 && n<com_no){
        for(i=0;i<=n;i++){
            printf("%s\n",history[i]);
        }
    }
    if(fill==0 && n>=com_no){
        for(i=0;i<=com_no;i++){
            printf("%s\n",history[i]);
        }
    }
}
void execute(char a[100]){
    if(com_no==19){
        fill = 1;
    }
    else if (a[0]=='e' && a[1]=='c' && a[2]=='h' && a[3]=='o' && a[4]==' '){
        echo(a);
        if(strcmp(history[com_no],"echo")!=0){
            com_no = (com_no+1)%20;
            strcpy(history[com_no],"echo");
        }
    }
    else if (a[0]=='p' && a[1]=='w' && a[2]=='d'){
        pwd();
        if(strcmp(history[com_no],"pwd")!=0){
            com_no = (com_no+1)%20;
            strcpy(history[com_no],"pwd");
        }
    }
    else if (a[0]=='c' && a[1]=='d'){
        if(a[2]=='\n'){
            chdir(home_dir);
        }
        else{
            cd(a,home_dir,prev_dir);
        }
        
        if(strcmp(history[com_no],"cd")!=0){
            com_no = (com_no+1)%20;
            strcpy(history[com_no],"cd");
        }
    }
    else if (a[0]=='l' && a[1]=='s'){
        get(a);
        if(strcmp(history[com_no],"ls")!=0){
            com_no = (com_no+1)%20;
            strcpy(history[com_no],"ls");
        }
    }
    else if (a[0]=='r' && a[1]=='e' && a[2]=='p' && a[3]=='e' && a[4]=='a' && a[5]=='t'){
        char *kl = repeat(a);
        int n = repeat2(a);
        for(i=0;i<n;i++){
            execute(kl);
        }
        if(strcmp(history[com_no],"repeat")!=0){
            com_no = (com_no+1)%20;
            strcpy(history[com_no],"repeat");
        }
    }
    else if (a[0]=='h' && a[1]=='i' && a[2]=='s' && a[3]=='t' && a[4]=='o' && a[5]=='r' && a[6]=='y'){
        
        if(strcmp(history[com_no],"history")!=0){
            com_no = (com_no+1)%20;
            strcpy(history[com_no],"history");
        }
        if(a[7]==' '){
            if(a[8]-'0' <=9 && a[8]-'0' >=0){
                displayn(a[8]-'0');
            }
        }
        else{
            display();
        }
        //display();
    }
    else if (a[0]=='q' && a[1]=='u' && a[2]=='i' && a[3]=='t'){
        exit(0);
    }
    else if (a[0]=='e' && a[1]=='x' && a[2]=='i' && a[3]=='t'){
        exit(0);
    }
    else{
        printf("Command not found\n");
    }
}

void spaces(char a[]){
    int i=0;
    char line[100]={'\0'};
    char *token = strtok(a," \t\n");
    if(token!= NULL){
        commands[i]=token;
        strcpy(line,commands[i]);
        i++;
    }
    strcat(line," ");
    while(token!= NULL){
        token = strtok(NULL, " \t\n");
        if(token!= NULL){
            commands[i]=token;
            strcat(line,commands[i]);
            strcat(line," ");
            i++;
        }
    }
    int ke= strlen(line);
    line[ke-1]='\n';
    //printf("%s",line);
    execute(line);
}

void semi_colon(char a[]){
    int i=0;
    char *token = strtok(a,";");
    while(token!= NULL){
        spaces(token);
        token = strtok(NULL,";");
    }
}

/*
void org(char input[],char o_input[]){
    char s[2] = ";";
    char *token;
    token = strtok(input,s);
    while(token!=NULL){
        strcat(o_input,token);
        strcat(o_input," ");
        token = strtok(NULL,s);
    }
}
void token(char input[]){
    int sc=0;
    while(input[i]!='\n'){
        if(input[i]==';'){
            sc++;
        }
        i++;
    }
    char commands[sc+1][100];
    i=0;
    j=0;
    while(input[j]!='\n'){
        for(i=0;i<=sc;i++){
            k=0;
            while(input[j]!=';'){
                if(input[j]==' ' || input[j]=='\t'){
                    if(input[j+1]!=' ' && input[j+1]!='\t' && input[j+1]!='\n'){
                        commands[i][k]=input[j];
                        k++;
                    }
                }
                else{
                    commands[i][k]=input[j];
                    k++;
                }
                j++;
            }
            commands[i][k+1]='\n';
            j++;
        }
    }
}*/

int main()
{
    getcwd(home_dir,100);
    strcpy(prev_dir,home_dir);
    while (1)
    {
        
        prompt(home_dir);
        int size = 100;
        char input[size],o_input[size];
        size_t bufSize =0;
        int inpu;
        char* scan = 0;
        inpu = getline(&scan,&bufSize,stdin);
        semi_colon(scan);
        /*if(strcmp("echo",input)==0){
            size_t bufSize =0;
            int input;
            char* scan = 0;
            input = getline(&scan,&bufSize,stdin);
            echo(scan);
        }
        
        if(strcmp("pwd",input)==0){
            pwd();
        }*/

        /*if(strcmp("cd",input)==0){
            
            size_t bufSize =0;
            int inpu;
            char* scan = 0;
            inpu = getline(&scan,&bufSize,stdin);
            strcat(input,scan);
            cd(input);
        }

        if(strcmp("repeat",input)==0){
            int n,i;
            scanf("%d",&n);
            char b[size];
            scanf("%s",b);
            repeat(n,b);
        }*/
    }
}