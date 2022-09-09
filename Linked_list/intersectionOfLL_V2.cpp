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

void traverse(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp ->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}


void intersection(Node* head, Node* head2)
{
    
}
int main()
{

    Node* head = new Node(1);
    Node* tail = head;

    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    Node* head2 = new Node(8);
    Node* tail2 = head2;
    insertAtTail(tail2,7);
    tail2->next = tail;
    insertAtTail(tail,5);
    insertAtTail(tail,6);


    traverse(head2);


    cout<<intersection(head,head2)->data<<endl;


}