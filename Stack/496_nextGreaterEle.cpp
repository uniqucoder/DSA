#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > nextGreater(vector<int> arr)
    {
        stack<int> s;
        s.push(INT_MAX);
        int n = arr.size();
        vector<pair<int,int>>vp(n);
        
        for(int i=n-1; i>=0; i--)
        {
            int item = arr[i];
            
            while(s.size()!=0 && item >= s.top())
            {
                s.pop();
            }
            if(s.top()==INT_MAX)
            {
               vp[i] = make_pair(arr[i],-1); 
            //    vp[i]=-1;    
            }
            else
            {
                // vp[i]= s.top();
               vp[i] = make_pair(arr[i],s.top()); 
                
            }
            
            s.push(item);
        }
        
        return vp;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<pair<int,int>> vp = nextGreater(nums2);
        

        for(int i=0;i<nums1.size();i++)
        {
            cout<<vp[nums1[i]].first<<" "<<vp[nums1[i]].second<<endl;
        }



        // vector<int>v(nums1.size());
        // for(int i=0;i<nums1.size();i++)
        // {
        //     v.push_back(vp[nums1[i]].second);
        // }
        
        
        // return v;
        
    }

int main()
{
    vector<int>nums1={4,1,2}; 
    vector<int>nums2={1,3,4,2};

    vector<int > vp  = nextGreaterElement(nums1,nums2);

    for(auto &x : vp)
    {
        cout<<x<<" ";
    }
    cout<<endl;

}
