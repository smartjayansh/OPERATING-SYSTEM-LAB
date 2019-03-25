#include<iostream>
using namespace std;
void algo(int arr[],int brr[],int id[],int size,int cpbrr[])
{
    int comp[size],turn[size],wait[size],min=1000,ti=0,index,check=0,count=0;
    while(count!=size)
    {
    
    for(int i=0;i<size;i++)
    {
        if(min>brr[i] && brr[i]!=0 && arr[i]<=ti)
        {
            min=brr[i];
            index=i;
            check=1;
        }
    }
    if(check==0)
    {
        ti++;
        continue;
    }
    brr[index]--;
    min=brr[index];
    if(min==0)
        min=1000;
    if(brr[index]==0)
    {
        count++;
        comp[index]=ti+1;
        turn[index]=comp[index]-arr[index];
        wait[index]=turn[index]-cpbrr[index];
        check=0;
    }
    ti++;
    }
    cout<<"PID  ART  BRT  CMP  TRT WAT\n";
    for(int j=0;j<size;j++)
    {
        cout<<" "<<id[j]<<"    "<<arr[j]<<"   "<<cpbrr[j]<<"    "<<comp[j]<<"   "<<turn[j]<<"   "<<wait[j]<<endl;
    }
}
int main()
{
    int arr[5]={2,7,6,3,5};
    int brr[5]={8,1,2,6,4};
    int id[5]={1,2,3,4,5};
    int cpbrr[5]={8,1,2,6,4};

    algo(arr,brr,id,5,cpbrr);
return 0;
}