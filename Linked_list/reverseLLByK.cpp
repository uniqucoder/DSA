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

void insertAtTail(Node* &tail, int d)
{
    Node* newNode = new Node(d);
    tail ->next = newNode;
    tail = newNode;

}
void traverse(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp ->data <<" ";
        temp = temp ->next;
    }

}

Node* reverseInK(Node* &head,int k)
{
    
    
    // step1 reveser first k nodes

    Node* curr = head;
    Node* prev = NULL;
    int count =0;
    Node* next = NULL;
    while(curr != NULL && count <k)
    {
        next = curr ->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL)
        head->next = reverseInK(next,k);
    

    return prev;


}
int main()
{
    Node* head = new Node(1);
    Node* tail = head;

    insertAtTail(tail ,2);
    insertAtTail(tail ,3);
    insertAtTail(tail ,4);
    insertAtTail(tail ,5);
    insertAtTail(tail ,6);
    insertAtTail(tail ,7);
    insertAtTail(tail ,8);

    traverse(head);   
    int k =3;
    Node* head2 = reverseInK(head, k);

    cout<<" Reverse LL is  "<<endl;
    traverse(head2);
    return 0;
}