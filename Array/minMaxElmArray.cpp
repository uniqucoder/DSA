#include<bits/stdc++.h>
using namespace std;

pair<int,int> getMinMax(int arr[], int n)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    pair<int,int> ans ;
    for(int i=1;i<n;i++)
    {
        if(arr[i] < mini)
        {
            mini = arr[i];
            ans.first = mini;
            // cout<<"value of mini"<<mini<<endl;
        }
        else if( arr[i] > maxi)
        {
            maxi = arr[i];
             ans.second = maxi;
        }
    }
    return ans;   
}

int main()
{
    int arr[] = {7,3,2,5,9};
    int n = 5;

    pair<int,int> ans = getMinMax(arr, n);

    cout<<ans.first<<" "<<ans.second<<endl;

    // getMinMax(arr, n);
}