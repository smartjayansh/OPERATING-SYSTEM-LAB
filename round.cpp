#include<iostream>
using namespace std;
struct node
{
    int pid;
    int art;
    int brt;
};
void bubble(node arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j].art>arr[j+1].art)
            {
                node temp;
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void round(node arr[],int quanta,int size)
{
    int comp[size],turn[size],wait[size],ti=0,count=0;
    int brr[size]={};
    for(int i=0;i<size;i++)
        brr[i]=arr[i].brt;
    ti+=arr[0].art;
    int i=0;
    while(count!=size)
    {
        i=0;
        while(arr[i].art<=ti)
        {
            if(arr[i].brt!=0)
            {
                if(quanta<arr[i].brt)
                {
                    arr[i].brt-=quanta;
                    ti+=quanta;                    
                }
                else
                {
                    ti+=arr[i].brt;
                    count++;
                    arr[i].brt=0;
                    comp[i]=ti;
                    turn[i]=comp[i]-arr[i].art;
                    wait[i]=turn[i]-brr[i];
                }
                
            }
            i++;
            if(count==size)
                break;
        }
    }
    cout<<"PID  ART  BRT  CMP  TRT WAT\n";
    for(int j=0;j<size;j++)
        cout<<" "<<arr[j].pid<<"   "<<arr[j].art<<"   "<<brr[j]<<"    "<<comp[j]<<"   "<<turn[j]<<"   "<<wait[j]<<endl;
    
    
}
int main()
{
    cout<<"Welcome to the Round Robin Program\n";
    int quanta;
    cout<<"Enter time quanta\n";
    cin>>quanta;
    node arr[6]={{1,4,4},{2,5,5},{3,1,7},{4,2,2},{5,3,1},{6,1,2}};
    bubble(arr,6);
    round(arr,quanta,6);
}