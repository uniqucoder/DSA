#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node* next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

};

void traverse(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp ->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}


Node* getMiddle(Node* &head)
{
    if(head == NULL)
        return NULL;
    
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow ->next;
        fast = fast ->next ->next;
    }

    return slow;
}

bool checkCircularLL(Node* head)
{
    Node* temp = head;

    
    while (temp != NULL)
    {
        if(temp ->next ==  head)
            return true;
        
        temp =  temp ->next;
    }
    return false;
        
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;


    // traverse(head);

    // cout<<getMiddle(head)->data;

    cout<<"LL is circular or not "<<checkCircularLL(head)<<endl;
}