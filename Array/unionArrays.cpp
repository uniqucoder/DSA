#include<bits/stdc++.h>
using namespace std;
// Using set
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

// Using map

int UnionMap(int a[], int n, int b[], int m)
{
    map<int,int>mp;

    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }
    
    for(int i=0;i<m;i++)
    {
        mp[b[i]]++;
    }

    return mp.size();
}

int unionNaive(int a[], int n, int b[], int m)
{
    vector<int>u;

    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        u.push_back(a[i]);
    }

    for(int i=0;i<m;i++)
    {
        if(!binary_search(a,a+n,b[i]))
        {
            u.push_back(b[i]);
        }
    }

    return u.size();

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


int intersection(int a[], int n, int b[], int m)
{
    unordered_map<int,int>mp;

    for(int i=0; i<n;i++)
    {
        mp[a[i]]++;
    }
    
    for(int i=0; i<m;i++)
    {
        mp[b[i]]++;
    }
    set<int>s;
    for(int i=0;i<n;i++)
    {
        if(mp[a[i]] > 1)
            s.insert(a[i]);
    }

    return s.size();

}
// using set and count method

// step1 : put all element of array1 into the set
// step2 : traverse array 2 , check count of array  value in the set if already present print that 


int intersectionCount(int a[], int n, int b[], int m)
{
    set<int>s;

    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    int cnt =0;
    for(int i=0; i<m; i++)
    {
        if(s.count(b[i]))
        {
            cout<<b[i]<<" ";
            cnt++;
        }
    }

    return cnt;
}


int main()
{
    int a[] = {1,2,3,4,5};
    int n = 5;

    int b[] = {1,2,3};
    int m = 3;

    // cout<<unionArray(a,n,b,m);

    // cout<<UnionMap(a,n,b,m)<<endl;
    cout<<unionNaive(a,n,b,m)<<endl;
    // cout<<"intersection "<<intersectionArray(a,n,b,m)<<endl;

    // cout<<"Intersection -> "<<intersection(a,n,b,m)<<endl;

    cout<<"\n Ans is "<<intersectionCount(a,n,b,m)<<endl;
}