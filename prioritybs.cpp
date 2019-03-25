#include<iostream>
using namespace std;
struct node
{
    int pid;
    int art;
    int brt;
    int pri;
};
void algo(node arr[],int size)
{
    int comp[6],turn[6],wait[6],index,count=0;
    int brr[6]={};
    for(int i=0;i<size;i++)
        brr[i]=arr[i].brt;

    int ti=0,p=1000,i=0;
    while(count!=size)
    {
        for(i=0;i<size;i++)
        {
            if(p>arr[i].pri && arr[i].art<=ti && arr[i].brt!=0)
            {
                p=arr[i].pri;
                index=i;
            }
        }
        if(p==1000)
            ti++;
        else
        {
            p=1000;
            ti+=arr[index].brt;
            arr[index].brt=0;
            comp[index]=ti;
            count++;
            turn[index]=comp[index]-arr[index].art;
            wait[index]=turn[index]-brr[index];    
        }
        
        
    }
    cout<<"PID  PRI ART  BRT  CMP  TRT WAT\n";
    for(int j=0;j<size;j++)
        cout<<" "<<arr[j].pid<<"    "<<arr[j].pri<<"   "<<arr[j].art<<"    "<<brr[j]<<"    "<<comp[j]<<"   "<<turn[j]<<"   "<<wait[j]<<endl;
        
}

int main()
{
    // link arr[6]={{1,1,4,4},{2,2,2,5},{3,2,6,7},{4,3,5,8},{5,3,1,5},{6,4,2,6}};
    node arr[6]={{1,1,4,4},{2,2,5,5},{3,3,1,7},{4,4,2,2},{5,5,3,1},{6,6,6,6}};
    algo(arr,6);
    cout<<endl;
return 0;
}