// Input : {1,2,3}
// output : {{},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}};

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

    solve(nums,output,index+1,ans);

    // include

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

    cout<<"Size is "<<ans.size()<<endl;
    cout<<"Col Size is "<<ans[7].size()<<endl;

    for(int i=0; i<ans.size();i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    
}