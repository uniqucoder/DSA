#include<bits/stdc++.h>
using namespace std;

int solve(string str1, string str2, int i, int j)
{
    if(i>= str1.size())
        return 0;
    
    if(j>=str2.size())
        return 0;
    
    int ans =0;
    // string char is match 
    if(str1[i] == str2[j])
    {
        ans = 1 + solve(str1,str2, i+1,j+1);
    }   
    else
    {
        ans = max(solve(str1,str2, i+1,j), solve(str1,str2, i,j+1));
    }

    return ans;
}

int main()
{
    string str1 ="abcdabc";
    string str2 = "bcbcda";

    cout<<"Ans is "<<solve(str1,str2, 0,0)<<endl;
}