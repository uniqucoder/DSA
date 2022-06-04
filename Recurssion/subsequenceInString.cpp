// Subsequence of a string 


#include<bits/stdc++.h>
using namespace std;

void subsequence(string str, int index,string output,vector<string>&ans)
{
    // base case

    if(index >=str.length())
    {
        if(output.length() > 0)
        {
            ans.push_back(output);
        }
        
        return;
        
    }

    // exclude
    subsequence(str,index+1,output,ans);

    //Include
    char ele = str[index];
    output.push_back(ele);
    subsequence(str,index+1,output,ans);


}

int main()
{
    string str = "abc";
    string output="";
    int index=0;
    vector<string>ans;
    subsequence(str,index,output,ans);
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size();i++)
    {
      cout<<ans[i]<<" ";  
    }

    return 0;
}