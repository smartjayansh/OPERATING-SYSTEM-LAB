#include<iostream>
using namespace std;

int arr[3][3]={{3,1,0},{1,4,0},{4,2,0}};
int tat[3],wat[3];
int t=0,k=0,count=0,i,bt;
void min_at()
{
    int z=0;
    while(count<3)
    {
        if(z>0)
        {
            i=0;
            int temp=arr[0][1],index=0;
            while(arr[i][0]<=t && arr[i][2]!=5)
            {
                if(arr[i][1]<temp)
                {
                    temp=arr[i][1];
                    index=i;
                }
                i++;
                
            }
            t=t+temp;
            tat[index]=t-arr[index][0];
            wat[index]= tat[index]- arr[index][1];
            arr[index][2]=5;
            count++;
        }
        else
        {
            int min=arr[0][0],index=0;
            for(i=0;i<3;i++)
            {
                if(min>arr[i][0])
                {
                    min=arr[i][0];
                    k=arr[i][1];
                    index=i;
                    arr[i][2]=5;
                }
            }
            
            t=t+k+min;
            tat[index]=t-arr[index][0];
            wat[index]= tat[index]-arr[index][1];
            count++;
            z++;
        }
        
    }
    
}
void display()
{
    cout<<"P_id  AT  BT  TAT  WT \n";
    for(int i=0;i<3;i++)
    {
        cout<<i<<"     "<<arr[i][0]<<"   "<<arr[i][1]<<"    "<<tat[i]<<"   "<<wat[i]<<endl;
    } 
}
int main()
{
    min_at();
    display();

return 0;
}