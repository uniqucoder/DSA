#include<bits/stdc++.h>
using namespace std;

void revsereString(string &str)
{
    stack<char> s;

    for(int i=0; i< str.length();i++)
    {
        s.push(str[i]);
    }
    str =""; 
    while(!s.empty())
    {
        str += s.top();
        s.pop();
    }
}

int main()
{
    string str = "abcd";

    revsereString(str);
    cout<<"reveserd String "<<str<<endl;
}