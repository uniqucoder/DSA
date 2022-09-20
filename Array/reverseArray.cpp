#include<bits/stdc++.h>
using namespace std;

// By using iteration

void reverse(int arr[], int n)
{
    int i =0;
    int j=n-1;

    while(i<=j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
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

void reverseRec(int arr[], int i, int j)
{
    if(i >=j)
        return;

    swap(arr[i],arr[j]);
    i++;
    j--;
    reverseRec(arr,i,j);
}
int main()
{
    int arr[]= {1,2,3,4,5};
    int n = 5;
    // By using Iteration
    // reverse(arr,n);

    // by using recursion

    reverseRec(arr,0,n-1);


    printArray(arr,n);
}