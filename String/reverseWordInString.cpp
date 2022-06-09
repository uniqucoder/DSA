#include<bits/stdc++.h>
using namespace std;

string reverseString(string str)
{
       // Write your code here.
  int l=str.length();
  int r=str.length();
    string temp="";
  while(r >= 0)
  {
      while(l >= 0 && str[l]!=' ')
      {
          l--;
      }
      temp.append(str.begin()+l+1,str.begin()+r+1);
      temp.push_back(' ');
    r=l-1;
    l=r;
  }
  return temp;
}

int main()
{
    string str="the sky is blue";

    cout<<reverseString(str)<<endl;
}