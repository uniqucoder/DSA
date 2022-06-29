#include<bits/stdc++.h>
using namespace std;


void sortedInsert(stack<int>&s, int ele)
{
    if(s.empty() || s.top() < ele)
    {
        s.push(ele);
        return;
    }

    

    int tele = s.top();
    s.pop();
    sortedInsert(s,ele);
    
    s.push(tele);


    
}

void sortStack(stack<int> &s)
{
    //base case
    if(s.empty())
    {
        return;
    }

    int topEle = s.top();
    s.pop();
    sortStack(s);

    sortedInsert(s,topEle);

}

void printStack(stack<int> &s)
{
    
    while( !s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}




int main()
{
    stack<int>s;

    s.push(2);
    s.push(4);
    s.push(1);
    s.push(3);


    sortStack(s);

    printStack(s);

    // while (!s.empty())
    // {   
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    

}