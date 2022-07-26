#include<bits/stdc++.h>
using namespace std;

class Heap
{
    public:
    int arr[250];
    int size;
    Heap()
    {
        size =0;
    }

    void insertIntoHeap(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        //take that value to its correct possition

        

        while( index > 1)
        {
            int parentIndex = index /2;
            if(arr[index] > arr[parentIndex])
            {   
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
                   
            }
            else
            {
                break;
            }
        }

    }


    void print()
    {
        for(int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteheap()
    {
        if(size <= 0)
        {
            cout<<"Max heap is already empty"<<endl;
        }

        swap(arr[1],arr[size]);
        size--;

        // root ko correct position mein bhejo

        int index = 1;

        while(index <= size)
        {
            int largestIndex = index;
            int left = 2 * index;
            int right = 2 * index + 1;

            if(left <= size  && arr[left] > arr[largestIndex] )
            {
                largestIndex = left;
            }
            if(right <= size && arr[right] > arr[largestIndex])
            {
                largestIndex = right;
            }

            if(largestIndex != index)
            {
                swap(arr[index],arr[largestIndex]);
                index = largestIndex;
            }
            else
            {
                break;
            }
        }
    }
};

void maxHeapify(vector<int> &arr, int size, int i)
{
    int largest = i;

    int left = 2 * i;
    int right = 2*i + 1;

    if(left <= size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right <= size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);

        maxHeapify(arr,size,largest);
    }

    return;
}


void minHeapify(vector<int>&arr, int size , int i)
{
    int smallest = i;

    int left = 2 * i;
    int right = 2 * i+1;

    if(left < size && arr[left] < arr[smallest] )
    {
        smallest = left;
    }
    if( right < size && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if(smallest != i)
    {
        swap(arr[smallest],arr[i]);
        minHeapify(arr, size, smallest);
    }
    return;
}


void Heapify(vector<int>&arr, int n , int i)
{
    int largest = i;

    int left = 2 * i;
    int right = 2 * i+1;

    if(left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        Heapify(arr, n, largest);
    }

    return;
}


void heapSort(vector<int> &arr, int n)
{
  
    int size = n;
    


    while(size >=1)
    {

        cout<<"For size = "<<size <<endl;
        for(auto &x : arr)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        //step 1:
        swap(arr[1],arr[size]);
        size--;

        //step 2:
        Heapify(arr,size,1);

    }
}

int main()
{
    // Heap maxHeap;

    // maxHeap.insertIntoHeap(2);
    // maxHeap.insertIntoHeap(6);
    // maxHeap.insertIntoHeap(8);
    // maxHeap.insertIntoHeap(3);
    // maxHeap.insertIntoHeap(7);

    // maxHeap.print();
    // maxHeap.deleteheap();

    // maxHeap.print();
    // maxHeap.deleteheap();
    // maxHeap.print();
    // maxHeap.deleteheap();
    // maxHeap.print();
    // maxHeap.deleteheap();
    // maxHeap.print();
    // maxHeap.deleteheap();

    // maxHeap.print();
    // maxHeap.deleteheap();

    vector<int> arr = {-1,4,3,2,5,1};
    int n = arr.size()-1;
    for(int i = n/2 ; i>0;i--)
    {
        maxHeapify(arr,n,i);
    }
    cout<<"Printing array"<<endl;
    for(int i =1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr, n);

    cout<<"Printing sorted array"<<endl;
    for(int i =1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;


}