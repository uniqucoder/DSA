#include<bits/stdc++.h>
using namespace std;

void swapBoundaryPairs(int arr[], int i, int j)
{
    if(i>j)
        return;
    
    swap(arr[i],arr[j]);
    i=i+2;
    j = j -2;
    swapBoundaryPairs(arr,i,j);
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n=6;

    swapBoundaryPairs(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}