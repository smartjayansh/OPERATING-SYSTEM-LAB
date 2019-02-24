#include<iostream>
using namespace std;
void bubble(int id[],int arr[],int brr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp1,temp2,temp3;
                temp3=id[j+1];
                temp1=arr[j+1];
                temp2=brr[j+1];
                id[j+1]=id[j];
                arr[j+1]=arr[j];
                brr[j+1]=brr[j];
                arr[j]=temp1;
                brr[j]=temp2;
                id[j]=temp3;
            }
        }
    }
}
void first(int id[],int arr[],int brr[],int size)
{
    int tim=0,com[size],turn[size],wait[size],i=0;
    while(i!=size)
    {
        if(i==0)
        {
            tim+=arr[i];
        }
            tim+=brr[i];
            com[i]=tim;
            turn[i]=com[i]-arr[i];
            wait[i]=turn[i]-brr[i];
        
        i++;
    }
    cout<<"P_ID  ART  BRT  CMP  TAT  WAT\n";
    for(int i=0;i<size;i++)
    {
        cout<<id[i]<<"     "<<arr[i]<<"     "<<brr[i]<<"    "<<com[i]<<"    "<<turn[i]<<"    "<<wait[i]<<endl;
    }

    
}
int main()
{
    int id[]={1,2,3,4};
    int arr[]={1,4,2,5};
    int brr[]={3,5,2,3};
    bubble(id,arr,brr,4);
    first(id,arr,brr,4);
    cout<<endl;
return 0;
}