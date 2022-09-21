#include<bits/stdc++.h>
using namespace std;


void rotateArray(int arr[], int n)
{
    int temp = arr[n];

    for(int i=n;i>0;i--)
    {
        swap(arr[i-1],arr[i]);
    }
    arr[0] = temp;
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
    int arr[] = {1,2,3,4,5,6};
    int n = 6;

    rotateArray(arr, n);

    printArray(arr,n);
}