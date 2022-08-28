#include<bits/stdc++.h>
using namespace std;


// int solve(int n, vector<int>&val,)

int main()
{
    int n = 3;

    vector<int> val,wt;

    val.push_back(60);
    val.push_back(100);
    val.push_back(120);

    
    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);

    int capacity = 50;
    int ans = solve(n,val,wt,capacity);
    cout<<ans;
}