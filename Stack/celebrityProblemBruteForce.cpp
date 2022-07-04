#include<bits/stdc++.h>
using namespace std;



void findCe2(int arr[2][2] , int n)
{
    int row=-1,col=-1;
    for(int i=0;i< n;i++)
    {
        // check for rows
        bool flagr=true;
        for(int j=0;j<n;j++)
        {
            if(arr[i][j] == 1 )
            {
                flagr = false;
                break;
            }
        }
        if(flagr == true)
        {
            row = i;
            bool flagCol = true;
            int k;
            for( k =0; k<n;k++)
            {
                if(arr[k][row] == 0 && k!= row)
                {
                    flagCol = false;
                    break;
                }
                
            }
            if(flagCol == true)
            {
                cout<<"celebrity is "<<row;
                return;
               
            }
        }
    }

   cout<<"No celeb"<<endl;
}

int findCelebrity(int arr[3][3], int n)
{
    //row sum
    vector<int> rowSum(n);
    for(int i=0;i<n;i++) 
    {   int sum =0;
        for(int j=0;j<n;j++)
        {   
            sum += arr[i][j];
        }
        rowSum[i]=sum;
    }
    cout<<"Row sum"<<endl;
    for(auto &x : rowSum)
    {
        cout<<x<<" ";
    }cout<<endl;

    int candidate;
    for(int i=0;i<n;i++)
    {
        if(rowSum[i]==0)
        {
            candidate = i;
        }
    }
   cout<<endl;
   cout<<"candidate  may present in this row"<<candidate<<" "<<endl;

    vector<int> colSum(n);
    for(int i=0;i<n;i++) 
    {   int sum =0;
        for(int j=0;j<n;j++)
        {   
            sum += arr[j][i];
        }
        colSum[i]=sum;
    }

    cout<<"col sum"<<endl;
    for(auto &x : colSum)
    {
        cout<<x<<" ";
    }cout<<endl;
   
   
    for(int i=0;i<n;i++)
    {
        if( colSum[i]==n-1 && rowSum[i] == 0)
        {
            return i;
            
        }
    }

    // if(candidate == cand)
    // {
    //     cout<<"celebrot  "<<cand;
    //     return cand;
    // }
 
   return -1;

}

int main()
{
    // int arr[4][4]={{0,0,1,0},{0,0,1,0},{0,0,0,0},{0,0,1,0}};
    int arr[2][2] = {{0,1},{1,0}};
    // int arr[3][3] ={{0,1,0},{0,0,0},{0,1,0}};
    
    // cout<<"Celebrity is "<<findCelebrity(arr,3)<<endl;

    findCe2(arr,2);
    
    
}