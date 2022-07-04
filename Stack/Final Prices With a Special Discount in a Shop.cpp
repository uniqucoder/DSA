class Solution {
public:
    //next smaller element logic
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        vector<int>ans(n);
        stack<int>s;
        s.push(0);
        for(int i=n-1;i >=0; i--)
        {
            int item = prices[i];
            
            while(s.top() > item)
            {
                s.pop();
            }
            int disAmt = item - s.top();
            ans[i] = disAmt;
            s.push(item);
        }
        
        return ans;
    }
};

Link:
https://leetcode.com/problems/count-of-smaller-numbers-after-self/
