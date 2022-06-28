#include<bits/stdc++.h>
using namespace std;

class Node
{   
    public:

    int data;
    Node* next;

    Node(int d)
    {
        this ->data = d;
        this ->next = NULL;
    }

}; 

void insertAttail(Node* &tail, int d)
{
    Node* newNode = new Node(d);

    tail -> next = newNode;

    tail = newNode;

}
void traverse(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";

        temp = temp ->next;
    }

}



// find and remove zero sum elements


Node* solve(Node* &head, bool &anyChange)
{
    if(head == NULL)
        return head;
    
    Node* temp = head;
    int sum = 0;
    while (temp != NULL)
    {
        sum = sum + temp -> data;

        if(sum == 0)
        {
            break;
        }
        temp = temp -> next;
        
    }
    // here will come out in two cases - 1) temp become NULL or we got sum == 0
    if(sum == 0)
    {   
        anyChange = true;
        return temp ->next;
    }
    
    head -> next = solve(head -> next, anyChange);

    return head;

}

Node* findZeroSum(Node * head)
{
   while(true)
   {
        bool anyChange = false;

        head = solve(head, anyChange);

        if(head == NULL || anyChange == false)
        {
            break;
        }
   }

   return head;
}
int main()
{
    Node* start = new Node(1);

    Node* head = start;
    Node* tail = start;

    insertAttail(tail,2);
    insertAttail(tail,-3);
    insertAttail(tail,3);
    insertAttail(tail,1);
    traverse(head);
    Node* ans = findZeroSum(head);

    cout<<endl;
    traverse(ans);





    






    return 0;
}