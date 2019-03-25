#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter number of processes\n";
    cin>>num;
    float brr[num];
    float pbrr[num],smooth,tau;
    cout<<"Enter Smoothening factor value and tau1 value\n";
    cin>>smooth>>tau;
    cout<<"Enter burst time of processes\n";
    for(int i=0;i<num;i++)
    {
        cin>>brr[i];
        if(i==0)
        {
            pbrr[i]=tau;
        }
        else
        {
            pbrr[i]=smooth*brr[i-1] + (1-smooth)*pbrr[i-1];
        }
        
    }
    cout<<"ABT  PBT\n";
    for(int i=0;i<num;i++)
        cout<<brr[i]<<"   "<<pbrr[i]<<endl;

}