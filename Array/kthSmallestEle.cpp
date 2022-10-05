#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    // setp1 : sort the array
    sort(arr,arr+n);\

    return arr[k-1];
}

// Bu usinh heap

// int kthSmaller(int arr[], int n, int k)
// {
//     priority_queue<int> pq;
//     // step1 : put k element in pq
//     for(int i=0; i<n;i++)
//     {
//         pq.push(arr[i]);
//         if(pq.size() > k)
//             pq.pop();
//     }
//     return pq.top();
// }


int kthSmaller(int arr[], int n, int k)
{
    priority_queue<int> pq;
    // step1 : put k element in pq
    for(int i=0; i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i =k;i<n;i++)
    {
        if(arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}




int main()
{
    int arr[] = {7,10,4,3,20,15};

    int n = 6;
    int k = 3;

    // cout<<kthSmallest(arr,n,k)<<endl;

    cout<<kthSmaller(arr,n,k)<<endl;
}