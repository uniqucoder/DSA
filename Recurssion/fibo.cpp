#include<bits/stdc++.h>
using namespace std;



// int fib(int n)
// {
//     int a = 0, b = 1, c, i;
//     if( n == 0)
//         return n+1;
//     if(n==1)
//     {
//         return n+1;
//     }
//     for(i = 2; i <= n; i++)
//     {
//        c = a + b;
//        a = b;
//        b = c;
//     }
//     return b+1;
// }


int fib(int n)
{
    // base case
    if(n==0 || n==1)
    {
        return n;
    }

    return fib(n-1)+fib(n-2);

}
int main()
{
    int n=2;

    cout<<fib(n);
}