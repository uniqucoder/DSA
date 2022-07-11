#include<bits/stdc++.h>
using namespace std;

class Deque{

    public:
    int *arr;
    int front;
    int rear;
    int size;

    Deque(int s)
    {
        arr = new int[s];
        front = -1;
        rear = -1;
        size = 1;
    }

    //push front 
    void pushFront(int element)
    {
        //for first elemet
        if(front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else if(front == -1 && rear != -1)
        {
            cout<<"Deque underflow"<<endl;
            return;
        }
        else
        {            
            //normal wala case
            front--;     
        }

        arr[front]=element;
    }

    //pop front

    void popFront()
    {
        if(front == -1 && rear== -1)
        {
            cout<<"deque underflow"<<endl;
            return;
        }
        else
        {
            //
            arr[front] = -1;
            front++;
        }
        if(front == rear)
        {
            front = rear =0;
        }
    }

    //get front

    int getFront()
    {
        if(front == -1)
        {
            return -1;
        }
        return arr[front];
    }


    //pushBack

    void pushback(int element)
    {
        //for first element
        if(front == -1 && rear == -1)
        {
            rear = front = 0;
        }
        else if(rear == size-1)
        {
            cout<<"deque full";
        }
    }




};

int main()
{

}