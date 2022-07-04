#include<bits/stdc++.h>
using namespace std;


vector<int> nextSmaller(vector<int> arr)
{
    int n = arr.size();
    stack<int> s;
    s.push(-1);
    vector<int>ans(n);

    for(int i = n-1; i>=0;i--)
    {
        int item = arr[i];
        while(s.top() >= item)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(item);

    }
    return ans;
}

// N2 solution of next smaller element 

vector<int> nextSmall(vector<int> arr)
{
    vector<int>ans;
    int n = arr.size();

    for(int i=0;i<n;i++)
    {
        int next = -1;
        for(int j = i+1; j< n; j++)
        {
            if(arr[j] <= arr[i] )
            {
                next = arr[j];
            }
        }
        ans.push_back(next);
    }

    return ans;
}

int main()
{
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(1);   
    arr.push_back(4);   
    arr.push_back(3);

    vector<int> ans = nextSmaller(arr);

    for(auto &x : ans)
    {
        cout<<x<<" ";
    }    

    return 0;
}