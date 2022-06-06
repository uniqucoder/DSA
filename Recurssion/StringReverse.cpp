// Leetcode 344

#include<bits/stdc++.h>
using namespace std;
void solve(vector<char> &s,int i,int j)
{
    // base case
    if(i>=j )
    {
        return;
    }

    swap(s[i],s[j]);
    i++;
    j--;

    solve(s,i,j);
}

void reverseString(vector<char> &s)
{
    int i=0;
    int j=s.size()-1;
    solve(s,i,j);
}

int main()
{
    vector<char> s={'H','a','n','n','a','h'};
    

    reverseString(s);

    for(auto &x:s)
    {
        cout<<x<<" ";
    }
    cout<<endl;

}