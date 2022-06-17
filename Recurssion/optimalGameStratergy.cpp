#include<bits/stdc++.h>
using namespace std;

int optimalStratergy(int arr[],int i, int j)
{
    // base case
    if(i > j)
    {
        return 0;
    }

    cout<<"Value of i"<<i<<" Value of j"<<j<<endl;
    int choice1 = arr[i] + min(optimalStratergy(arr,i+2,j),optimalStratergy(arr,i+1,j-1)); 
    cout<<"Choice 1 - >"<<choice1<<endl;
    int choice2 =arr[j] + min(optimalStratergy(arr,i+1,j-1),optimalStratergy(arr,i,j-2));
    cout<<"Choice 2 - >"<<choice2<<endl;

    int ans  = max(choice1,choice2);
    cout<<"Ans -> "<<ans<<endl;
    return ans;
}

int main()
{
    int arr[]={8,15,3,7};
    int i=0;
    int j=3;
    cout<<optimalStratergy(arr,i,j);
}