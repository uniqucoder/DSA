#include<iostream>
#include<queue>

using namespace std;



int kthSmallest(vector<int> &arr,int n, int k)
{
    
    priority_queue<int> pq;

    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }

    for(int i =k; i<n;i++)
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

    vector<int> arr = {7,10,4,20,15};
    int n = arr.size()-1;   
    int k =2;

    cout<<kthSmallest(arr,n, k);

    return 0;



}