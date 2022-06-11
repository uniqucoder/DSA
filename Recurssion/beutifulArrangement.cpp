#include<bits/stdc++.h>
using namespace std;

bool checkBeutiful(vector<int>&arr,int n)
{
    cout<<"Checking in beutiful"<<endl;


    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<endl;

    // for(int i=0;i<arr.size();i++)
    // {
    //     if( ((arr[i] % i+1) !=0)  || ((i+1 % arr[i]) !=0) )
    //     {
    //         cout<<"Excuted fasle"<<endl;
    //         return false;
    //     }
    // }

    return true;
}

void solve(int index ,vector<int>&arr,vector<vector<int>>&result,int n)
{
    cout<<"In solve"<<endl;
    // base case
    if(index >= arr.size())
    {

        if(checkBeutiful(arr,n))
        {
            cout<<"adding array to result"<<endl;
            result.push_back(arr);
        }
       
        return;
    }

    for(int i=index; i<arr.size();i++)
    {
        swap(arr[i],arr[index]);
        
        solve(index+1,arr,result,n);

        swap(arr[i],arr[index]);
        
    }


   
}

int main()
{
   
    int n = 3;

    vector<int>arr;

    for(int i=0;i<n;i++)
    {
        arr.push_back(i+1);
    }
    int index=0;
    vector<vector<int>>result;
    solve(index,arr,result,n);



    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }

    }
    return 0;

    
}