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

Node* mergeTwoSorted(Node* &head1, Node* &head2)
{
    //base case
    if(head1 == NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head1;
    }

    Node* temp1 = head1;
    

    Node* temp2 = head2;
    // Node* tail1 = temp2;

    Node* newNode = new Node(-1);
    Node* tail1 = newNode;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1 -> data <= temp2 -> data)
        {
            tail1 -> next = temp1;
            tail1 = temp1;
            temp1 = temp1 ->next;
            tail1 ->next = NULL;
        }
        else
        {   
            tail1 ->next = temp2;
            tail1 = temp2;
            temp2 = temp2 ->next;
            tail1 ->next = NULL;
        }
        
    }

    if(temp1 != NULL)
    {
        tail1->next= temp1;
    }
    if(temp2 != NULL)
    {
        tail1 -> next = temp2;
    }
    

    Node* remove = newNode;
    newNode= newNode -> next;
    remove ->next = NULL;
    
    delete remove;
    

    return newNode ;

}

int main()
{

    // LL 1
    Node* head1 = new Node(1);
    Node* tail1 = head1;
    insertAttail(tail1,3);
    insertAttail(tail1,5);    
    insertAttail(tail1,7);


    // LL 2
    Node* head2 = new Node(2);
    Node* tail2 = head2;
    insertAttail(tail2,4);
    insertAttail(tail2,6);    
    insertAttail(tail2,8);

    traverse(head1);
    cout<<endl;

    traverse(head2);
    cout<<endl;
    


    Node* head = mergeTwoSorted(head1,head2);


    traverse(head);


    return 0;



}