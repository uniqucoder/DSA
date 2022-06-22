#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }

};

void insertAttail(Node* &tail, int d)
{
    Node* newNode = new Node(d);
    tail ->next = newNode;

    tail = newNode;
}

void traverse(Node* &head)
{
    Node* temp = head;

    while(temp !=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
}
int getLen(Node* &head)
{
    Node* temp = head;
    int len=0;
    while(temp!=NULL)
    {
        len++;
        temp = temp -> next;   
    }
    return len;
}

void deleteAtPos(Node* &head , Node* &tail, int pos)
{
    // pos = 1;

    if(pos == 1)
    {
        delete(head);
    } 
    else
    {
        Node* prev = head;
        int t = pos -2;

        while(t--)
        {
            prev = prev->next;
        }

        Node* removeNode = prev ->next;

        prev ->next = removeNode->next;

        delete(removeNode);
        int len = getLen(head);
        if(pos == len)
        {
            tail = prev;
        }
        
    }

}

void inssertAttail(Node* &tail, int d)
{
    Node* temp = new Node(d);

    tail -> next = temp;
    tail= temp;
}


void deleteByValue(Node* &head,Node* &tail, int target, int pos)
{
    //check of first node

    Node* temp = head;
    if(temp ->data == target && pos == 1)
    {
        head = head ->next;
        temp->next= NULL;

        delete temp;
    }
        else
    {
        Node* prev = head;
        Node* temp = head;

        while(temp->data != target)
        {
            prev = temp;
            temp = temp->next;
            pos++;


        }
        int len = getLen(head); 
        prev ->next = temp -> next;
        temp ->next = NULL;
        delete(temp);
        
        if(pos == len)
        {
            tail = prev;
        }
    }
}

int main()
{
    Node* first = new Node(1);

    Node* head = first;

    Node* tail= first;

    insertAttail(tail,2);
    insertAttail(tail,3);
    insertAttail(tail,4);
    insertAttail(tail,5);

    traverse(head);
    cout<<endl;

    // deleteAtPos(head,tail,3);

    insertAttail(tail,100);

    deleteByValue(head,tail,100,1);
    insertAttail(tail,200);
    traverse(head);
    cout<<endl;

}