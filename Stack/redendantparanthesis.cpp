#include<bits/stdc++.h>
using namespace std;

bool checkRedundant(string s)
{
    
    stack<char> st;

    for(int i=0; i < s.length(); i++)
    {
        char ch = s[i];
        if(ch == '(' || ch =='+' || ch == '-' || ch == '/' || ch == '*')
        {
            st.push(ch);
        }
        else if(ch == ')')
        {
            bool isRedundent = true;
            while(st.top() != '(')
            {
                char top = st.top();

                if( top =='+' || top == '-' || top == '/' || top == '*')
                    isRedundent = false;

                st.pop();
            }
            

            if(isRedundent == true)
            {
                return true;
            }
            st.pop();
        }
    }

    return false;
}

int main()
{
    string str = "(a+(b*(a/c)))";
    if(checkRedundant(str))
    {
        cout<<"Redundent bracket present"<<endl;
    }
    else
    {
        cout<<"Redundent bracket not present"<<endl;
    }

    return 0;
}