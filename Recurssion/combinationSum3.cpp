#include<bits/stdc++.h>
using namespace std;

void solve(int k, int n, vector<vector<int>>&output, vector<int>temp,int index)
{
    // base case

    cout<<"For N = "<< n<<" "<<"K = "<<k<<endl;
    if(k==0 && n==0)
    {
        output.push_back(temp);

        for(int i=0; i< temp.size();i++)
        {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        
        return;
    }

    for(int i=index; i<10;i++)
    {
        // special case
        
        cout<<"for i = "<<i<<endl;
        if(i > n)
        {
            break;
        }
        temp.push_back(i);

        

        solve(k-1,n-i,output,temp,i+1);

        temp.pop_back();
    }

}

vector<vector<int>> combination(int k,int n)
{
    vector<vector<int>>output;
    vector<int>temp;

    solve(k,n,output,temp, 1);

    return output;
}

int main()
{
    int k=3;
    int n =7;
    vector<vector<int>> ans;

    ans = combination(k,n);

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