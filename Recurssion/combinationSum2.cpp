#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&candidates,int target, vector<vector<int>>&output, vector<int>temp,int index)
{
    // base case
    if(target == 0)
    {
        output.push_back(temp);
        return;
    }
    if(target < 0 || index > candidates.size())
    {
        return;
    }

    for(int i=index; i<candidates.size();i++)
    {
        // special case
        if(i > index && candidates[i]==candidates[i-1]){
            continue;
        }

        if(candidates[i] > target)
        {
            break;
        }

        temp.push_back(candidates[i]);

        solve(candidates,target-candidates[i],output,temp,i+1);

        temp.pop_back();
    }

}

vector<vector<int>> combination(vector<int>&candidates,int target)
{
    vector<vector<int>>output;
    vector<int>temp;

    solve(candidates,target,output,temp, 0);

    return output;
}

int main()
{
    vector<int> candidates={1,2,2,2,5};
    int target = 5;
    // For exclude and include
    vector<vector<int>> ans;

    ans = combination(candidates,target);

    for(int i=0;i<ans.size();i++)
    {
        cout<<"[";
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";

        cout<<" ";

        
    }
}