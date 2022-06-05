#include<bits/stdc++.h>
using namespace std;



void solve(string str, string output, int index , vector<string>& ans)
{

    // base case
    if(index >= str.length())
    {
       if(output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }

    // exclude
    solve(str,output,index+1,ans);

    // Include
    char ch = str[index];
    output.push_back(ch);
    solve(str,output,index+1,ans);

}


int main()
{

    string str = "abc";
    string output = "";

    vector<string> ans;
    int index=0;

    solve(str,output,index,ans);

    // print ans
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}