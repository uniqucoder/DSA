#include<bits/stdc++.h>
using namespace std;

bool anagram(string s, string t)
{
    map<char,int> m1;

    for(int i=0; i<s.length();i++)
    {
        m1[s[i]]++;
    }

    
    map<char,int> m2;

    for(int i=0; i<t.length();i++)
    {
        m2[t[i]]++;
    }

    // for(auto &x:m1)
    // {
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    
    // for(auto &x:m2)
    // {
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    // for(auto &i:m1)
    // {
    //     if(i.second != 0)
    //     {
    //         return false;
    //     }
    // }

    for(int i=0;i<s.length();i++)
    {
        if(m1[s[i]] != m2[t[i]] )
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s="cat";

    string t="rat";

    if(anagram(s,t))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}