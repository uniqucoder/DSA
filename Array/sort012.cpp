#include<bits/stdc++.h>
using namespace std;


void sort012(int arr[], int n)
{
    // Buuble sort

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


void sort012_Count(int arr[], int n)
{
    int c0=0,c1=0,c2=0;


    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
            c0++;
        if(arr[i]==1)
            c1++;
        if(arr[i]==2)
            c2++;
    }

    int index=0;
    while(c0--)
    {
        arr[index++] =0;
    }
    while(c1--)
    {
        arr[index++] =1;
    }
    while(c2--)
    {
        arr[index++] =2;
    }
}
void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = {1,2,0,1,2,0};
    int n = 6;

    sort012_Count(arr,n);


    printArray(arr, n);
}