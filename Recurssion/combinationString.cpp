/*
    CombinatioN Of digits with space

    input = 123
    o/p: 123
        12_3
        1_23
        1_2_3




*/

#include<bits/stdc++.h>
using namespace std;

void combinationString(string str, string &temp, int index, vector<string>&ans)
{
    // base case
    if(index >= str.length())
    {
        ans.push_back(temp);
        cout<<temp<<endl;
        return;
    }

    // exclude
    temp.push_back(str[index]);
    combinationString(str,temp,index+1,ans);

    // include

    temp.push_back('_');
    

    if(str[index+1] !='\0')
    {
        
        combinationString(str,temp,index+1,ans);
        
    
    }
    temp.pop_back();
    temp.pop_back();

}

int main()
{
    string str="123";
    vector<string>ans;
    string temp;
    int index=0;
    combinationString(str,temp,index,ans);
}