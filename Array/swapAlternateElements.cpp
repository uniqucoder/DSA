#include<bits/stdc++.h>
using namespace std;

void swapAltenate(int arr[], int n)
{
    for(int i=0;i<n;i=i+2)
    {
        swap(arr[i],arr[i+1]);
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
    int arr[] = {1,2,3,4,5};
    int n = 5;


    swapAltenate(arr, n);

    printArray(arr,n);


}