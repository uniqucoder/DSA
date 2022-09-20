#include<bits/stdc++.h>
using namespace std;

int unionArray(int a[], int n, int b[], int m)
{
    set<int>s;
    vector<int>v;
    v.insert(v.begin(),a,a+n);
    v.insert(v.end(),b,b+m);

    s.insert(v.begin(),v.end());


    for(auto &x : s)
        cout<<x<<" ";
    cout<<endl;
    return s.size();
}

int intersectionArray(int a[], int n, int b[],int m)
{
    // Take a map to keep track of element present in both the array
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }

    set<int>s;
    for(int i=0;i<m;i++)
    {
        if(mp[b[i]] >=1)
            s.insert(b[i]);

    }
    return s.size();
}

int main()
{
    int a[] = {1,2,3,4,5};
    int n = 5;

    int b[] = {1,2,3};
    int m = 3;

    // cout<<unionArray(a,n,b,m);

    cout<<"intersection "<<intersectionArray(a,n,b,m)<<endl;
}