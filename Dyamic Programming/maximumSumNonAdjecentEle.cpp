#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int index )
{
    if(index >= arr.size())
    {
        return 0;
    }
    
    //include

    int incl = arr[index] + solve(arr,index+2); 

    int excl =  solve(arr,index+1);

    return max(incl,excl);
}

int solveMem(vector<int>& arr,int index, vector<int>&dp )
{
    if(index >= arr.size())
    {
        return 0;
    }
    

    if(dp[index] != -1)
    {
        return dp[index];
    }
    //include

    int incl = arr[index] + solveMem(arr,index+2,dp); 

    int excl =  solveMem(arr,index+1,dp);

    return dp[index]=max(incl,excl);
}


int solvetab(vector<int>arr)
{
    //step1: Create Dp vector
    vector<int>dp(arr.size()+2, 0);
    int n = arr.size();
    for(int index = n-1; index >=0; index--)
    {
        
        int incl = arr[index] + dp[index+2]; 

        int excl =  dp[index+1];

        dp[index] = max(incl,excl);
    }

    return dp[0];
}


int solvetabSO(vector<int>arr)
{
    //step1: Create Dp vector
 

    int next1 = 0;
    int next2 = 0;
    int curr;
    int n = arr.size();
    for(int index = n-1; index >=0; index--)
    {
        
        int incl = arr[index] + next2; 

        int excl =  next1;

        curr = max(incl,excl);

        //move next1 and next 2 
        next2 = next1;
        next1 = curr;

        
    }

    return curr;
}


int main()
{
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(9);

    int n = arr.size();
    // vector<int>dp(n+1,-1);
    cout<<solvetabSO(arr)<<endl;


    
}