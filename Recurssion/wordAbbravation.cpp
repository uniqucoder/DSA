#include<bits/stdc++.h>
using namespace std;



void solve(string &str,vector<string>&ans, string output,int index)
{
    // base
    if(index >=str.length())
    {
        ans.push_back(output);
        return;
    }

        // include

    output.push_back(str[index]);
    solve(str,ans,output,index+1);
    output.pop_back();

   
// set count of digits to 1
    int count = 1;
 
    // addition the adjacent digits
    if (!output.empty()) {
 
        if (isdigit(output.back())) {
 
            // get the digit and increase the count
            count += (int)(output.back() - '0');
 
            // remove the adjacent digit
            output.pop_back();
        }
    }
   
    char ch = char(count);
    output.push_back(ch);
    solve(str,ans,output,index+1);
    output.pop_back();


    
  


}

vector<string>wordAbbravation(string str)
{
    vector<string> ans;

    string output="";

    solve(str,ans,output,0);

    return ans;
}

int main()
{
    string str="ABC";

    vector<string>ans;

    ans = wordAbbravation(str);

    for(int i=0; i< ans.size() ; i++)
    {
        for(int j = 0; ans[i].size(); i++)
        {
            cout<<ans[i][j];
        }
        cout<<" ";
    }

    return 0;
}