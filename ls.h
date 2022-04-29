#ifndef __LS_H
#define __LS_H
void file_char(mode_t mode);
void ls(char str[]);
void ls2(char str[]);
void ls3(char str[]);
void ls4(char str[]);
void get(char a[]);
void file_stat_store(char path[],char file[]);
void file_details(struct stat *file_pe);
void per(mode_t mode);

#endif