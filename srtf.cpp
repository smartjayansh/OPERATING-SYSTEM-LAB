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
void algoSrtf(int id[], int arr[], int brr[], int cpbrr[], int size)
{
    int ti=0,comp[size],turn[size],wait[size];
    int count=0;
    ti=ti+arr[0];
    
    int i=0,k;
    int temp=0,index;
    while(count<size)
    {
        if(brr[i]==0)
        {
            i++;
            count++;
            comp[i]=ti;
            continue;
        }
        temp=0;
        ti=ti+1;
        brr[i]--;
        if(brr[i]==0)
        {
            i++;
            count++;
            comp[i]=ti;
        }
        else
        {
            k=brr[i];
            while(arr[temp]<=ti)
            {
                if(k>brr[temp] && brr[temp]!=0) 
                {
                    k=brr[temp];
                    index=temp;
                }
                else
                {
                    index=i;
                }
                temp++;
            }
            i=index;
        }
    }
    for(int i=0;i<size;i++)
    {
        turn[i]=comp[i]-arr[i];
        wait[i]=turn[i]-brr[i];
    }
    cout<<"PID  ART  BRT  CMP  TRT WAT\n";
    for(int i=0;i<size;i++)
    {
        cout<<" "<<id[i]<<"    "<<arr[i]<<"   "<<cpbrr[i]<<"   "<<comp[i]<<"   "<<turn[i]<<"   "<<wait[i]<<endl;
    }

}
int main()
{
    int num;
    // cout<<"Enter number of processes\n";
    // cin>>num;
    num=4;
    int id[num]={1,2,3,4}, arr[num]={3,2,1,4};
    int brr[num]={2,4,3,5},cpbrr[num];

    bubble(id,arr,brr,num);
    for(int i=0;i<num;i++)
        cpbrr[i]=brr[i];
    algoSrtf(id,arr,brr,cpbrr,num);
return 0;
}























    // ti+=1;
        // if(i==0)
        // {
        //     brr[i]--;
        //     k=brr[i]
        // }
        // int j=0,ind;
        // while(arr[j]<=ti && brr[j]!=0)
        // {
        //     if(k>=brr[j])
        //     {
        //         k=brr[j];
        //         ind=j;                
        //     }
        // }
        // ti+=1;
        // brr[j]--;
        // if(brr[j]==0)
        // {
        //     comp[j]=ti;
        //     count++;
        // }