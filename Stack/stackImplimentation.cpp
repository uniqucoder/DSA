#include<bits/stdc++.h>
using namespace std;


class Stack
{
    public:
    int *arr;
    int top;
    int size;

    //Constructor

    Stack(int size)
    {
        arr = new int[size];
        top = -1;
        this ->size = size;
        
    }
    //
    void push(int d)
    {
        // if(top == size-1)
        // {
        //     cout<<"Stack Overflow"<<"for "<< d<<endl;
        //     return;
        // }  
 
        top++;

        cout<<"inserting at index "<<top<<" value " <<d<<endl; 
        arr[top] = d;

    }

    int getSize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        return false;
   }

   int getTop()
   {
    return arr[top];
   }

   void getPop()
   {
        if(top == -1)
        {
            cout<<"Stack under flow "<<endl;
        }
        top--;        
   }

};
int main()
{

    // stack<int> st;


    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }



    // Stack *st = new Stack(5);
    Stack st = Stack(5);

    // st->push(1);
    // st->push(2);
    // st->push(3);
    // st->push(4);
    // st->push(5);
    // st->push(6);

    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout<<st.getTop()<<endl;
    


    // cout<<st->isEmpty()<<endl;

    // cout<<st->getTop()<<endl;

    // st->getPop();
    // st->getPop();
    // st->getPop(); 
    // st->getPop();
    // st->getPop();
    // st->getPop();
    


    // cout<<st->getTop()<<endl;
    

    return 0;
}