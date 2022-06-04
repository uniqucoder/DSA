// Input : {1,2,3}
// output : {{},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}};


// Approch :
/*
    Here we use recursion to keep track of elements in array , 

    As we want all subset of the array and there are total 3 elements in and array, the 2^n are the number of powerset elements

    what we did we travse the array and at each index we decide either exclude that element or include.

    and the base case when index is equal to the size of the array.
    
    and storing the output in ans vector.
    


*/


#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int>output,int index, vector<vector<int>> &ans)
{

    // Base case   
    if(index>=nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclude call 

    solve(nums,output,index+1,ans);

    // Include call

    int ele = nums[index];
    output.push_back(ele);
    solve(nums,output,index+1,ans);
    
}

int main()
{
    vector<int>nums={1,2,3};

    vector<vector<int>> ans;
    vector<int>output;
    int index=0;

    solve(nums,output,index,ans);


    for(int i=0; i<ans.size();i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    
}