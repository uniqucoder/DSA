#include<bits/stdc++.h>
using namespace std;

class Queue
{
public:

    int *arr;
    int rear;
    int front;
    int size;
    
    //constructor
    Queue(int n)
    {   
        arr = new int[size];
        rear = 0;
        front =0;
        size = n;    
    }

    //push

    void push(int element)
    {
        if(rear == size)
        {
            cout<<"Queue OverFlow"<<endl;
        }
        else
        {
            arr[rear] = element;
            rear++;
        }
    }

    //pop

    void pop()
    {
        if(rear == front)
        {
            cout<<"Queue UnderFlow"<<endl;
        }
        else
        {
            arr[front]=-1;
            front++;

            if(rear == front)
            {
                front = rear = 0;
            }


        }
    }

    //get front

    int getFront()
    {
        return arr[front];
    }

    //getsize

    int getSize()
    {
        return rear - size;
    }

    //isempty

    bool isEmpty()
    {
        if(rear == front)
        {
            return true;
        }
        return false;

    }




};



int main()
{

    Queue *q = new Queue(5);


    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);

    cout<<"Size of Queue "<<q->getSize()<<endl;

    cout<<"Front element of Queue"<<q->getFront()<<endl;

    q->pop();
    cout<<"Front element of Queue"<<q->getFront()<<endl;


    //traverse queue

    while (!q->isEmpty())
    {
        cout<<q->getFront()<<" ";
        q->pop();

    }   
    


    return 0;
}