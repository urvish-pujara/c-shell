## SHELL

THE shell includes the following functions:
1. echo
2. prompt display
3. pwd
4. cd
5. ls
6. history
7. history num
8. repeat
9. exit
10. quit

No pre-requisites 

## Files:

- Makefile : Contains Files to be compiled to run the shell.

- main.c :  Runs the shell theough main function.
            Manages tokens and extra spaces.
            Executes commands.
            Stores history.

- echo.c :  Contains echo function to print text on shell.

- pwd.c : Contains pwd function to print present working directory.

- cd.c : Contains cd function to change current directory to some other directory.

- prompt.c : Contains the prompt function that prints username hostname and shows the current directory.

- ls.c : Contains get,ls,ls2,ls3,ls4,etc. functions that basically manages -a,-l flags for ls command that list files in mentioned directory.

- repeat.c : Contains repeat and repeat2 function to repeat other cmmands a number of times.

NOTE: Tilde represents the directory executing the shell.

## Assumptions:
1. All the text input should be of maximum size 100.
2. Maximum history stored is 20.
3. Maximum history output can be 10 comands.
4. If less commands are run than number mentioned in history n then the number of commands that are run will be shown.