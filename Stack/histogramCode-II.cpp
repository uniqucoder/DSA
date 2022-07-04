// Optimise code

#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> &arr)
{
    stack<int> s;
    s.push(-1);
    int n = arr.size();

    vector<int> ans(n);

    for(int i=n-1; i>=0; i--)
    {
        int item = arr[i];

        while(s.top() != -1 && arr[s.top()] >= item)
        {
            s.pop();
        }
        //push in to ans
        if(s.top() == -1)
        {
            ans[i] = n;
        }
        else
        {
            ans[i] = s.top();
        }

        s.push(i);

    }
    return ans;
}

vector<int> prevSmaller(vector<int> &arr)
{
    stack<int> s;
    s.push(-1);
    int n = arr.size();

    vector<int> ans(n);

    for(int i=0; i<=n; i++)
    {
        int item = arr[i];

        while(s.top() != -1 && arr[s.top()] >= item)
        {
            s.pop();
        }
        //push in to ans
        if(s.top() == -1)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }

        s.push(i);

    }

    return ans;
}



int largestArea(vector<int> arr)
{

    vector<int>ns = nextSmaller(arr);
    vector<int>ps= prevSmaller(arr);

    int maxArea = INT_MIN;

    

    for(int i =0; i< ns.size();i++)
    {
        int length = arr[i];
        int breadth = ns[i] - ps[i] - 1;
        int newArea = length * breadth;

        maxArea = max(maxArea, newArea);
    }

    return maxArea;

}



// n2 solution


int maxArea1(vector<int> heights)
{
    int ans=INT_MIN;
    
    for(int i=0;i<heights.size();i++){
        
        int l=i-1;
        int r=i+1;
        //int lIndex=0;
        while(l>=0){
            if(heights[i]<=heights[l])
                l--;
            else{
                break;
            }
        }
        while(r<=heights.size()-1){
            if(heights[i]<=heights[r])
                r++;
            else{
                break;
            }
        }
        
        
        int total_length=(r-i)+(i-l-1);
        
        ans= max(ans,total_length*heights[i]);
        
    }
    return ans;

}

int main()
{


    vector<int>arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);

    vector<int> ns = nextSmaller(arr);
    vector<int> ps = prevSmaller(arr);

    cout<<"Next Smaller"<<endl;
    for(auto &x : ns)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"prev Smaller"<<endl;
    for(auto &x : ps)
    {
        cout<<x<<" ";
    }


    // total area coverrd by rectangle

    int maxArea = largestArea(arr);

    cout<<"largest area in hinstogram is "<<maxArea<<endl;

    
    // cout<<"Maximum Area is "<<maxArea1(arr);


}