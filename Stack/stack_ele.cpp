#include<bits/stdc++.h>
using namespace std;

int solve(stack<int>&s)
{
    int *ptr = 23;
}

int main()
{
    stack<int> s;

    int n=5;

    while(n--)
    {
        int a ;
        cin>>a;
        s.push(a);
    }


    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }

    int size = n /2 +1;

    while(size--)
    {
        s.pop();

    }
    cout<<s.top()<<endl;


    // recurssion func

    cout<< solve(s);

    return 0;

}