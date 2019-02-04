#include<stdio.h>
#include<unistd.h>
void example()
{
	int x=1;
	if(fork()==0)
		printf("Child process x value is %d\n",++x);
	else
		printf("Parent process x value is %d\n",--x);
}
int main()
{
	example();
	return 0;
}
