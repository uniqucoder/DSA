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


Node* interSection(Node* headA, Node* headB)
{
    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }

    Node* a = headA;
    Node* b = headB;

    while (a != b)  
    {
        a = a==NULL ? headB : a ->next;
        b = b == NULL ? headA : b-> next;
    }

    return a;
    

}

int main()
{
    Node* first  = new Node(1);
    Node* head2 = new Node(3);
    Node* head = first;
  
    Node* tail2 = head2;
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

    insertAttail(tail2,4);
    insertAttail(tail2,5);
    tail2 -> next = temp;


    Node* ans = interSection(head,head2);

    cout<<"Ans is :-> "<<ans -> data;
    
}