#include<iostream>
#include<queue>
using namespace std;

int main()
{
    //max heap
    priority_queue<int>pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    // pq.pop();
    // pq.pop();
    // cout<<"top element is "<<pq.top()<<endl;

    while(pq.size() > 1)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    cout<<pq.size()<<endl;


    cout<<"Min heap"<<endl;

    priority_queue<int,vector<int> , greater<int> > minHeap;

    minHeap.push(10);
    minHeap.push(9);
    minHeap.push(8);
    minHeap.push(7);
    minHeap.push(6);


    cout<<minHeap.size()<<endl;
    
    cout<<"Cout printing minHeap elements"<<endl;

    while (!minHeap.empty())
    {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }

    
    





}

