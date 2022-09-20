#include<bits/stdc++.h>
using namespace std;


void moveToFront(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr[j] < 0)
                swap(arr[i],arr[j]);
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
                swap(arr[i],arr[j]);
        }
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
    int arr[] = {-12,11,-13,-5,6,-7,5,-3,-6};
    int n = 9;

    // moveToFront(arr, n);

    moveToEnd(arr,n);
    printArray(arr,n);

}