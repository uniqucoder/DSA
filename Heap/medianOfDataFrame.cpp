#include<bits/stdc++.h>
using namespace std;


int getMidAns(vector<int> l, int n)
{
    int ans = -1;

    if(n == 0)
    {
        return l[0];
    }
    else if(n%2 != 0)
    {
        ans = l[n/2];
    }
    else
    {
        ans = (l[n/2 - 1] + l[n/2 ]) /2 ;
        
    }
    return ans;
}
vector<int> getMedian(vector<int>arr, int n)
{
    vector<int>ans;


    for(int i=0;i<n;i++)
    {
        sort(arr.begin(), arr.begin()+i);
        int medianAns = getMidAns(arr,i);

        ans.push_back(medianAns);

    }
}

int main()
{
    vector<int>arr={1,2,3,4,5};
    int n = 5;


    vector<int>ans = getMedian(arr, n);


    for(auto &x : ans)
    {
        cout<<x<<" ";
    }cout<<endl;
}