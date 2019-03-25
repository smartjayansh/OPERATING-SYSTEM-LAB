#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter number of processes\n";
    cin>>num;
    float brr[num];
    float pbrr[num],sum=0;
    cout<<"Enter burst time of processes\n";
    for(int i=0;i<num;i++)
    {
        cin>>brr[i];
        sum+=brr[i];
        pbrr[i]=sum/(i+1);
    }
    cout<<"Actual    burst time -- ";
    for(int i=0;i<num;i++)
        cout<<brr[i]<<"  ";
    cout<<endl;
    cout<<"Predicted burst time -- ";
    for(int i=0;i<num;i++)
        cout<<pbrr[i]<<"  ";
    cout<<endl;

}