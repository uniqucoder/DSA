#include<bits/stdc++.h>
using namespace std;

class Node
{   
    public:

    int data;
    bool vis;
    Node* next;

    Node(int d)
    {
        this ->data = d;
        this ->vis = false;
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

//by using 3rd pointer

Node* detect_Loop(Node * &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp ->vis == false)
        {
            temp-> vis = true;
        }
        else
        {
         
            return temp;
        }
   
    }
    return NULL;

}






// By using Floyds Cycle detection Algorithm 
// and delete the loop 


Node* detectCycle(Node* head)
{
    //base case

    if(head == NULL)
    {
        return NULL;
    }
    Node* slow = head;
    Node * fast = head;

    while(fast -> next != NULL && fast ->next ->next != NULL)
    {
        slow = slow -> next;

        fast = fast ->next ->next;

        if(slow == fast)
        {
            return slow;
        }
    }

    return NULL;

}


bool deleteCycle(Node* head)
{
    if(head == NULL)
        return true;
    
    Node* fast = detectCycle(head);

    Node* slow = head;

    while(slow != fast)
    {
        slow = slow ->next;
        fast = fast ->next;
    }

    Node* begining = slow;

    while(fast ->next != begining)
    {
        fast = fast ->next;
    }
    fast ->next = NULL;

    return true;
}


int main()
{
    Node* first  = new Node(1);

    Node* head = first;
    Node* tail = first;

    insertAttail(tail,2);
    insertAttail(tail,3);
    
    insertAttail(tail,4);
    insertAttail(tail,5);
   
    insertAttail(tail,6);
    Node* temp = tail;
    insertAttail(tail,7);
    insertAttail(tail,8);
    insertAttail(tail,9);
    tail ->next = temp;
    

    cout<<deleteCycle(head)<<endl;

    traverse(head);
}