#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr,int n,int target)
{

    int start=0;
    int end = n-1;
    int mid = (start + end )/2;

    while(start <= end)
    {
        if(arr[mid]==target)
        {
            return true;
        }
        if(target < arr[mid])
        {
            end = mid-1;
        }
        else
        {
            start = mid +1;
        }
        mid = (start + end )/2;
 
    }

    return false;
}

int main()
{
    int n=5;
    // cin>>n;

    // int *arr = new int[n];
    int arr[]={1,2,3,4,5};

    int target=5;
   

    if(binarySearch(arr,n,target))
    {
        cout<<"Present"<<endl;  
    }
    else
    {
        cout<<"Not Present"<<endl;
    }

}