#include<bits/stdc++.h>
using namespace std;

bool isMatching(char a, char b)
{
    if((a=='(' && b == ')') || (a=='{' && b == '}') || (a=='[' && b == ']'))
    {
        return true;
    }
    return false;
}

bool validParanthesis(string str )
{
    stack<char>st;

    for(int i=0;i<str.length();i++)
    {
        char ch  = str[i];
        if(ch =='(' || ch =='{' || ch =='[')
        {
            st.push(ch);
        }
        else
        {
            if(st.empty())
            {
                return false;
            }
            if(isMatching(st.top(),ch))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if(st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main()
{
    string str = "}";

    if(validParanthesis(str))
    {
        cout<<"Valid "<<endl;
    }
    else
    {
        cout<<"Not Valid"<<endl;
    }
}