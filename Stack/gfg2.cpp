#include<bits/stdc++.h>
using namespace std;

int findMaxi(vector<int> v1, int N)
{
    
    sort(v1.rbegin(),v1.rend());
    int sum1 =0;
    for(int i=0;i<N;i++)
    {
        sum1 +=v1[i]; 
    }

    return sum1;

}

int findMini(vector<int> v2, int N)
{
    sort(v2.begin(),v2.end());
    int sum1 =0;
    for(int i=0;i<N;i++)
    {
        sum1 += v2[i]; 
    }

    return sum1;
}

long long colosseum(int N,vector<int> A) {
    
    int first  = 0;
    int second = A.size()/2;
    vector<int>v1;
    for(int i=0;i<second;i++)
    {
        v1.push_back(A[i]);
    }

    for(auto &x : v1)
    {
        cout<<x<<" ";
    }cout<<endl;
    int maxi = findMaxi(v1,N); 
    cout<<maxi<<endl;

    vector<int>v2;
    for(int i=second;i<A.size();i++)
    {
        v2.push_back(A[i]);
    }

    for(auto &x : v2)
    {
        cout<<x<<" ";
    }
    int mini = findMini(v2,N); 
    cout<<endl;
    cout<<mini<<endl;

    return maxi - mini;
}

int main()
{
    vector<int> A = {1,3,5,2,1,1};
    int N= 2;

    cout<<colosseum(N,A)<<endl;


}