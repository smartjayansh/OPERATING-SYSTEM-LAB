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
    int comp[4],turn[4],wait[4],p,ti=0,index,count=0;
    int brr[6]={};
    for(int i=0;i<size;i++)
        brr[i]=arr[i].brt;

    while(count!=size)
    {
        p=0;
        for(int i=0; i<size; ++i)
            if(p<arr[i].pri && arr[i].brt!=0 && arr[i].art<=ti)
            {
                p=arr[i].pri;
                index=i;
            }
        ti++;
        if(p!=0)
        {
            arr[index].brt--;
            if(arr[index].brt==0)
            {
                count++;
                comp[index]=ti;
                turn[index]=comp[index]-arr[index].art;
                wait[index]=turn[index]-brr[index];
            } 
        }
    }
    cout<<"PID  PRI ART  BRT  CMP  TRT WAT\n";
    for(int j=0;j<size;j++)
        cout<<" "<<arr[j].pid<<"    "<<arr[j].pri<<"  "<<arr[j].art<<"   "<<brr[j]<<"    "<<comp[j]<<"   "<<turn[j]<<"   "<<wait[j]<<endl;
    
}

int main()
{
    // node arr[6]={{1,1,4,4},{2,2,5,5},{3,3,1,7},{4,4,2,2},{5,5,3,1},{6,6,6,6}};
    node arr[6]={{1,1,4,4},{2,2,2,5},{3,2,3,7},{4,3,5,8},{5,3,1,5},{6,4,2,6}};
    algo(arr,6);
    cout<<endl;
return 0;
}