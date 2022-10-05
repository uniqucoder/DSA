#include<bits/stdc++.h>
using namespace std;

// Algo using Sort
int findDuplicate(vector<int>v, int n)
{
    sort(v.begin(), v.end());

    for(int i=1;i<n;i++)
    {
        if(v[i] == v[i-1])
            return v[i];
    }
    return -1;
}


// algo using map

int findD(vector<int>&v, int n)
{
    unordered_map<int,int>mp;

    for(int i=0; i<n; i++)
    {
        mp[v[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        if(mp[v[i]] >1)
            return v[i];
    }

    return -1;
}

int main()
{
    vector<int> v = {1,2,3,4,4};
    int n = 5;

    cout<<findD(v,n)<<endl;
}