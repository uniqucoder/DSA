#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;

    // halft pyramid
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    cout<<"\n\n";
    // Inverted half

    for(int row= 0;row <= n;row++)
    {
        for(int col = 0; col <= n-row-1;col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    cout<<endl;
    // right angle triangle

    for(int row=0;row <=n;row++)
    {
        // print space
        for(int col =0;col<n-row;col++)
        {
            cout<<" ";
        }
        for(int col = 0;col<row;col++)
        {
            cout<<"*";
        
        }
        cout<<endl;
    }
}