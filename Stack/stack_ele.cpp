#include<bits/stdc++.h>
using namespace std;





void printMiddle(stack<int>& st, int totalSize) {

   if(st.size() == 0)
   {
        cout<<"Stack is Empty"<<endl;
        return;
   }

   if((totalSize) == st.size())
   {
        cout<<"Middle element is "<<st.top()<<endl;

        return;
   }

   int topEle = st.top();

   st.pop();
   printMiddle(st,totalSize);

   st.push(topEle);

}

void insertAtBottom(stack<int> &s, int topEle)
{
    // base case
    if(s.empty())
    {
        s.push(topEle);
        return;
    }

    int ele = s.top();
    s.pop();
    insertAtBottom(s,topEle);

    s.push(ele);
}

void reverseStack( stack<int> &s)
{
    //base case
    if(s.empty())
    {
        return;
    }
    
    int topEle = s.top();
    s.pop();
    reverseStack(s);

    insertAtBottom(s,topEle);

}


void printStack(stack <int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int size = s.size();

    int n = (size /2) + 1;


    // printMiddle(s, n);
    printStack(s);
    cout<<endl;
    reverseStack(s);

    printStack(s);

    return 0;

}