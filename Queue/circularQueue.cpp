#include<bits/stdc++.h>
using namespace std;

class CircularQueue
{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int s)
    {
        arr = new int[s];
        front =-1;
        rear = -1;
        size = s;
    }

    //Insert (Enqueue ) 

    void enqueue(int element)
    {
        //Overflow
        if((front == 0 && rear == size -1 ) || (rear ==(front -1)%size ) )
        {
            cout<<"Overflow hogya"<<endl;
        }
        else if(front == -1)
        {
            //first element
            rear = front =0;
        }
        else if(front!=0 && rear == size-1)
        {
            //circular wala
            rear = 0;
        }
        else
        {
            // /normal
            rear++;
        }

        arr[rear] = element;

        
       
    }


};

int main()
{

    CircularQueue *q = new CircularQueue(5);

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(5);
    
    





}