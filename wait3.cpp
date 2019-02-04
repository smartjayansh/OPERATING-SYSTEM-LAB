#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 
void chmodexample() 
{ 
    int i, stat; 
    pid_t pid[5]; 
    for (i=0; i<3; i++) 
    { 
        pid[i] = fork();
        exit(i); 
    } 
    for (i=0; i<3; i++) 
    { 
        pid_t cpid = waitpid(pid[i], &stat, 0); 
        if (WIFEXITED(stat)) 
            printf("Child %d terminated with status: %d\n", 
                   cpid, WEXITSTATUS(stat)); 
    } 
}
int main() 
{ 
    example(); 
    return 0; 
} 
