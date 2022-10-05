#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void moveToFront(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr[j] < 0)
            {
            
                swap(arr[i+1],arr[j]);
                printArray(arr,n);
            }
        }
    }
}

void moveToEnd(int arr[], int n)
{
    for(int i=n-1; i>=0;i--)
    {
        for(int j=i; j>=0;j--)
        {
            if(arr[j] < 0)
            {
                swap(arr[i],arr[j]);
                // printArray(arr,n);
            }
        }
    }
}

int main()
{
    int arr[] = {1,-2,-3};
    int n = 3;

    moveToFront(arr, n);

    // moveToEnd(arr,n);
    printArray(arr,n);

}