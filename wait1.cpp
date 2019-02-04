#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main()
{
    int pid;
    int status;
    pid=fork();
    if(pid==-1)
    {
        cout<<"Not Created\n";
        exit(1);
    }
    if(pid==0)
    {
        cout<<"Child Successful\n";
        exit(20);


    else
    {
        wait(&status);
        cout<<"Status is "<<WEXITSTATUS(status)<<endl;
        cout<<"Parent Created\n";
    }
return 0;    
}