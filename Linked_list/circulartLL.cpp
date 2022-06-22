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
        /* code */
        cout<<temp ->data<<" ";
        temp = temp ->next;
    } while (temp!=head);
    
}


int main()
{
    Node* first = new Node(1);



    Node* head = first;
    Node* tail = first;

    

    
    traverse(first);



}