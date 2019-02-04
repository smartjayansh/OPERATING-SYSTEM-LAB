#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main()
{
    pid_t cpid;
    int status;
    if(fork()==0)
    {
        cout<<"Child id is "<<getpid()<<endl;
        exit(2);
    }
    else
    {
        cpid =  wait(&status);
        cout<<"Parent's id is "<<getpid()<<endl;
        cout<<"Child's id is "<<cpid<<endl;
        cout<<"Status is "<<WEXITSTATUS(status)<<endl;
    }
return 0;
}