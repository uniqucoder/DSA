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
        this -> next = NULL;
    }

};



void traverse(Node* &head)
{
    Node* temp = head;

    do
    {
        
        cout<<temp ->data<<" ";
        temp = temp ->next;
    } while (temp!=head);
    
}

//insert  at empty list

void insertEmpty(Node* &head,Node* &tail, int d)
{
    if(head == NULL)
    {
        Node* newNode = new Node(d);
        head = newNode;
        
        tail = head;
        tail ->next = head;
    }
}

//insert at first node

void insertFirst(Node* &head,Node* &tail, int d)
{

    Node* newNode = new Node(d);

    newNode ->next = head;
    head = newNode;
    tail -> next = head;

}

// insert after 
void insertafter(Node* &head, Node* & tail , int target, int d)
{
    Node* temp = head;
    while(temp != NULL && temp ->data != target)
    {
        temp = temp ->next;

    }
   
    Node* newNode = new Node(d);
    if(temp == NULL)
    {
      tail = newNode;
      tail->next = head;  
    } 
    newNode ->next = temp ->next;
    temp->next = newNode;
    
}

// insert at end

void insertEnd(Node* &head,Node* &tail, int d)
{
    Node* newNode = new Node(d);
    tail ->next = newNode;
    tail = newNode;
    tail ->next = head;
}

int main()
{

    Node* head = NULL;
    Node* tail = NULL;

    insertEmpty(head, tail, 1);
    insertEnd(head, tail,5);
    insertafter(head,tail, 1,2);
    insertafter(head,tail,2,3);
    // insertafter(head,tail, 1,2);
    insertafter(head,tail,2,10);
    
    traverse(head);
    

}