#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node* prev;
    int data;
    Node* next;


    Node(int d)
    {
        this ->prev = NULL;
        this ->data = d;
        this ->next = NULL;

    }

};

void insertAthead(Node* &head,int d)
{
    Node* newNode = new Node(d);

    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
    

}

void insertAtTail(Node* &tail, int d)
{
    Node* newNode = new Node(d);

    tail -> next = newNode;
    newNode ->prev= tail;
    tail = newNode;

}

int getLen(Node* &head)
{
    Node* temp = head;
    int len=0;
    while(temp != NULL)
    {
        len++;
        temp = temp -> next;
    }

    return len;
}

void insertAtPos(Node* &head,Node* &tail, int pos, int d)
{   
    int len = getLen(head);

    if(pos > len+1)
    {
        return;
    }
    
    if(pos == 1)
    {
        insertAthead(head,d);
    }
    else
    {
        

        if(pos == len+1)
        {
            insertAtTail(tail,d);
        }
        else
        {
            Node* newNode = new Node(d);

            Node* temp = head;
            Node* prev=NULL;
            int t = pos-1;
        
            while(t--)
            {
                prev = temp;
                temp = temp -> next;

            }

            newNode->next = temp;
            temp ->prev = newNode;
            prev -> next = newNode;
            newNode -> prev = prev;
       
        }

        
       

    }
}


void traverse(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp ->data<<" ";

        temp = temp->next;
    }
}
int main()
{
    Node* first = new Node(1);

    Node* head = first;
    Node* tail = first;

    insertAthead(head,3);

    insertAtTail(tail,4);

    insertAtPos(head,tail,4,400);
    // insertAtTail(tail,400);
    traverse(head);



    return 0;




}