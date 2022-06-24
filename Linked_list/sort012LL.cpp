#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next ;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAttail(Node* &tail, int d)
{
    if(tail == NULL)
    {
        Node* newNode = new Node(d);
        // head= newNode;
        tail = newNode;
    }
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

//sort using link changing approch
Node* sort012(Node* &head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    //1
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    //2
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;


    

    Node*temp = head;
    Node* next = NULL;
    while(temp != NULL)
    {
        if(temp ->data == 0)
        {
            next = temp->next;
            zeroTail->next = temp;
            temp ->next = NULL; 
            zeroTail = temp;

            temp = next;
        }

        if(temp ->data == 1)
        {
            next = temp->next;
            oneTail->next = temp;
            temp ->next = NULL; 
            oneTail = temp;

            temp = next;
        }

        if(temp ->data == 2)
        {
            next = temp->next;
            twoTail->next = temp;
            temp ->next = NULL; 
            twoTail = temp;

            temp = next;
        }
        temp = temp -> next;
    }

    return zeroHead->next;
}


//Sort 012 using count
Node* sort012Count(Node* &head)
{
    Node* temp = head;
    int c0=0,c1=0,c2=0;
    Node* headStart = new Node(-1);
    while(temp != NULL)
    {
        if(temp -> data == 0)
        {
            c0++;
        }
        if(temp -> data == 1)
        {
            c1++;
        }
        if(temp -> data == 2)
        {
            c2++;
        }
        temp = temp ->next;

    }
    Node* temp1 = headStart;

    while(c0--)
    {
        Node* newNode = new Node(0);
        temp1 ->next = newNode;
        temp1 = newNode;
    }
    
    while(c1--)
    {
        Node* newNode = new Node(1);
        temp1 ->next = newNode;
        temp1 = newNode;
    }
    while(c2--)
    {
        Node* newNode = new Node(2);
        temp1 ->next = newNode;
        temp1 = newNode;
    }
    return headStart->next;

}


int main()
{
    Node* first = new Node(1);

    Node* head = first;
    Node* tail = first;


    insertAttail(tail,0);
    insertAttail(tail,0);
    insertAttail(tail,1);
    insertAttail(tail,1);
    insertAttail(tail,2);
    insertAttail(tail,2);

    traverse(head);


    // Node* head2 = sort012Count(head);

    Node* head1 = sort012(head);
    cout<<endl;
    traverse(head1);

}