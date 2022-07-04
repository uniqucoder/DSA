#include<bits/stdc++.h>
using namespace std;



void deleteMiddle(stack<int>&s, int mid)
{
    if(s.size() == mid)
    {
        s.pop();
        return;
    }
    int topEle = s.top();
    s.pop();
    deleteMiddle(s,mid);

    s.push(topEle);


}

// void printStack(stack<int> &s){

//     while(!s.empty())
//     {
//         cout<<s.top()<<" ";
//         s.pop();
//     }

// }
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int size = s.size();
    int mid = (size /2) +1;
    deleteMiddle(s,mid);

    // printStack(s);


    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    

    return 0;

}