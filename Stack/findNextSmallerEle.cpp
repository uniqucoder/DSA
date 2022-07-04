#include<bits/stdc++.h>
using namespace std;

 vector<int> get_next(vector<int> &arr,int n){
        stack<int> s;
        s.push(-1);
        vector<int> next(n);
        
        for(int i = n - 1; i>=0; i--){
            while(!s.empty() && s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            next[i] = s.top();
            s.push(i);
        }
        return next;
    }

int main()
{
    vector<int> arr = {2,1,4,3};
    int n =4;

    vector<int> a = get_next(arr,n);

    for(auto &x : a)
    {
        cout<<x<<" ";
    }
}