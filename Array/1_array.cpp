#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;

    int *arr = new int[5];

    cout<<"Enter 5 elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int sum=0;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    cout<<sum<<endl;


}