void sortedInsert(stack<int>&s, int ele)
{
    if(s.empty() || s.top() < ele)
    {
        s.push(ele);
        return;
    }

    

    int tele = s.top();
    s.pop();
    sortedInsert(s,ele);
    
    s.push(tele);


    
}

void sortStack(stack<int> &s)
{
    //base case
    if(s.empty())
    {
        return;
    }

    int topEle = s.top();
    s.pop();
    sortStack(s);

    sortedInsert(s,topEle);

}