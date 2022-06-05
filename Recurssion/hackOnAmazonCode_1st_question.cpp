// This solution is working on local on that platform it will not printing the output.
// So Done this code for the day !




#include<bits/stdc++.h>
using namespace std;

void solve(int profits[],int n,int query[],int m,int index,vector<int>&cnt)
{
    
    if(index>= n)
    {
        
        // ans.push_back(profits);
        cout<<"Permutation"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<profits[i]<<" ";
        }
        cout<<endl;
        int cntProfit=0;
        for(int i=0;i<n;i++)
        {
            cntProfit  = cntProfit + profits[i]/pow(2,i); 
            
        }
        cnt.push_back(cntProfit);

        return;
    }
    


    for(int j = index; j <n;j++)
    {
        swap(profits[index],profits[j]);
        solve(profits,n,query,m,index+1,cnt);
        swap(profits[index],profits[j]);
    }

}

int main()
{
    int input1[]={10,25,4};
    int input2=3;
    int input3[]={25,30};
    int input4=2;

    vector<int>cnt;
    sort(input3,input3+input4);
    
    solve(input1,input2,input3,input4,0,cnt);
    sort(cnt.begin(),cnt.end());

    for(int i=0;i<cnt.size();i++)
    {
        cout<<cnt[i]<<" ";
    }

    cout<<endl;
    cout<<"Result"<<endl;
    for(int i=0;i<input4;i++)
    {   int count=0;
        for(int j=0;j<cnt.size();j++)
        {   

            if(cnt[j] > input3[i] )
            {
                count++;
            }
        }
        cout<<count<<" ";
    }
    cout<<endl;
}