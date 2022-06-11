#include<bits/stdc++.h>
using namespace std;


// Using For LOOP

void solve_1(vector<int>&candidates , int target, set<vector<int>>&output , vector<int>temp,int index)
{
    for(int i=0; i< candidates.size();i++)
    {
        if(target == 0)
        {
            sort(temp.begin(),temp.end());
            output.insert(temp);
            return;
        }
        if(target <0)
        {
            return;
        }
        if(i >index  && candidates[i]==candidates[i-1])
            return;
        if(candidates[i] > target)
            return;
        

        temp.push_back(candidates[i]);
        solve_1(candidates,target - candidates[i],output,temp,index+1);        
        temp.pop_back();
    }
}





void solve(vector<int>&candidates , int target, vector<vector<int>>&output , vector<int>temp,int i)
{
    // base case
    if(target == 0)
    {
        output.push_back(temp);
        return;
    }

    if(target < 0 || i >= candidates.size())
    {
        return;
    }

    // exclude
    solve(candidates,target,output,temp,i+1);

    // include
    temp.push_back(candidates[i]);
    solve(candidates,target-candidates[i],output,temp,i);
    temp.pop_back();
}

set<vector<int >> combination(vector<int>&candidates , int target)
{
   

    vector<int> temp;

    // Using Exclude Include
    //  vector< vector<int > >output;
    // solve(candidates,target,output,temp,0);

    // Using for loop
    set< vector<int > >output;
    solve_1(candidates,target,output,temp,0);

    return output;


}


void print1(vector<int>v)
{
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    

    vector<int> candidates={1,2,3,4};
    int target = 4;
    // For exclude and include
    // vector<vector<int>> ans;

    // ans = combination(candidates,target);

    // for(int i=0;i<ans.size();i++)
    // {
    //     cout<<"[";
    //     for(int j=0; j<ans[i].size(); j++)
    //     {
    //         cout<<ans[i][j]<<"";
    //     }
    //     cout<<"]";

    //     cout<<" ";

        
    // }

    // For using for loop

    set<vector<int>> ans;
    ans = combination(candidates,target);

    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        print1(*it);
    }
}