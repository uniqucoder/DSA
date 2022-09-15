#include<bits/stdc++.h>
using namespace std;


//1st Maximum sum of non adjencent elements
// rec
int solve(vector<int>&arr, int index)
{
    //base case
    if(index >= arr.size())
    {
        return 0;
    }

    int incl = arr[index] + solve(arr, index+2);

    int excl = 0 + solve(arr, index+1);

    return max(incl, excl);

}

// rec + mem

int solveMem(vector<int>&arr, int index,vector<int>&dp)
{
    //base case
    if(index >= arr.size())
    {
        return 0;
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }
    int incl = arr[index] + solveMem(arr, index+2,dp);

    int excl = 0 + solveMem(arr, index+1,dp);

    return dp[index]=max(incl, excl);

}


// tabulation
// only convert recursive function calls into DP
int solvetab(vector<int>&arr)
{
    //create Dp array
    int n = arr.size();
    vector<int>dp(n+1, 0);

    // step2 : analyase the base of 

    for(int index = n-1 ; index >=0;index--)
    {
        int incl = arr[index] + dp[index+2];

        int excl = dp[index+1];

        dp[index]=max(incl, excl);
    }

    return dp[0]; 
} 

// Space optimisation
int solvetabSO(vector<int>&arr)
{
    int next1 = 0;
    int next2 = 0;
    int n = arr.size();
    int curr = 0;
    for(int index = n-1 ; index >=0;index--)
    {
        int incl = arr[index] + next2;

        int excl = next1;

        curr =max(incl, excl);

        next2 = next1;
        next1 = curr;
    }

    return curr; 
} 

// Question 2
// Rod cutting problem

int getCuts(int n, int a, int b ,int c)
{
    //base case
    if(n==0)
        return 0;
    
    if(n < 0)
        return INT_MIN;
    

    int first = getCuts(n-a,a,b,c);
    int second = getCuts(n-b,a,b,c);
    int third = getCuts(n-c,a,b,c);

    return 1 + max(first,max(second,third));


}
int getCutsMem(int n, int a, int b ,int c, vector<int>&dp)
{
    //base case
    if(n==0)
        return 0;
    
    if(n < 0)
        return INT_MIN;
    
    if(dp[n] != -1)
    {
        return dp[n];
    }

    int first = getCutsMem(n-a,a,b,c,dp);
    int second = getCutsMem(n-b,a,b,c,dp);
    int third = getCutsMem(n-c,a,b,c,dp);

    return dp[n] = 1 + max(first,max(second,third));

}

// tabulation method

int getCutstab(int nth, int a,int b, int c)
{
    // step 1 create Dp vector

    vector<int> dp(nth+1,INT_MIN);
    dp[0]= 0;

    for(int n = nth -1 ;n >=0; n--)
    {
        int first = dp[n-a];
        int second = dp[n-b];
        int third = dp[n-c];

        dp[n] = 1 + max(first,max(second,third));
    }

    return dp[nth];
}

int main()
{

    // vector<int> arr = {2,1,4,9};
    // int n = arr.size();
    // vector<int>dp(n+1,-1);
    // cout<<"max sum of "<<solve(arr, 0);
   
    // cout<<"max sum of "<<solveMem(arr, 0,dp);

    // cout<<"tab "<<solvetabSO(arr)<<endl;

    // 2nd Qustion


    int N = 17;
    int a = 10;
    int b =11;
    int c = 3;


    // vector<int>dp(N+1,-1);
    // cout<<"get maximum cuts are "<<getCutsMem(N,a,b,c,dp)<<endl;

    cout<<"Ans is => "<<getCutstab(N,a,b,c);

    return 0;
}