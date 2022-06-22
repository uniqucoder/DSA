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

Node* reverseLL(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL)
    {
        Node* forward = curr ->next;
        curr -> next = prev;

        prev = curr;
        curr = forward;
    }

    return prev; 
   
}


Node* reverseRec(Node* &curr, Node* prev)
{
    // base case
    if(curr == NULL)
    {
        return prev;
    }

    
    Node* forward = curr ->next;
    curr -> next = prev;

    return reverseRec(forward,curr);

}

int main()
{
    Node* first = new Node(1);
    Node* head = first;
    Node* tail = first;
    insertAttail(tail, 2);
    insertAttail(tail, 3);
    insertAttail(tail, 4);

    traverse(head);
    cout<<endl;
    head = reverseRec(head, NULL);

    traverse(head);

    return 0;


}