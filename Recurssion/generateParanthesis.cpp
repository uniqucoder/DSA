#include<bits/stdc++.h>
using namespace std;


void solve(int currOpen, int currClose, int remOpen,int remClose,vector<string> &result,string output)
{
    /*
    cout<<currOpen<<" "<<currClose<<" " <<remOpen<<" "<<remClose<<" ";

    for(auto &x : result)
    {
        cout<<x<<" ";
    }cout<<endl;

    */
    // base case

    if(remClose == 0 && remOpen==0)
    {
        result.push_back(output);
        return;
    }

    // for open (

    if(remOpen > 0)
    {
        output.push_back('(');
        solve(currOpen+1,currClose,remOpen-1,remClose,result,output);
        output.pop_back();
    }

    // close

    if(remClose > 0 && currOpen > currClose)
    {
        output.push_back(')');
        solve(currOpen,currClose+1,remOpen,remClose-1,result,output);
        output.pop_back();
    }
}


vector<string> generateParanthesis(int n)
{
    vector<string> result;

    string output="(";

    int currOpen=1;
    int currClose=0;

    int remOpen =n-1;
    int remClose = n;

    solve(currOpen,currClose,remOpen,remClose,result,output);

    return result;

}
int main()
{
    int n =3;
    
    vector<string> ans;
    ans = generateParanthesis(n);

    for(auto &x : ans)
    {
        cout<<x<<" ";
    }

    return 0;
}