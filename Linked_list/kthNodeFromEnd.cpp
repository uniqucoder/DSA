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

int countKfromLast(Node* &head, int k)
{
    if(head == NULL)
    {
        return 0;
    }


    int cnt = countKfromLast(head->next , k) + 1;

    if(cnt == k)
    {
        cout<<"kth element from last is "<<head->data<<endl;
    }

    return cnt;

}



// remove and delete cycle from linkedlist

Node* detectLoop(Node* &head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next ->next;

        if(slow == fast)
        {
            return slow;
        }
    }

    return NULL;

}

bool deleteLoop(Node* head)
{
    

    if(head == NULL)
    {
        return false;
    }

    Node* fast = detectLoop(head);
    if(fast == NULL)
    {
        return false;
    }

    // find beginning of loop
    Node* slow = head;


    while( slow != fast )
    {
        slow = slow -> next;
        fast = fast -> next;
    }

    Node* beginningNOde = slow;

    Node* temp = beginningNOde;

    // NULL the node before beginnig node to remove loop

    while(temp -> next != beginningNOde)
    {
        temp = temp ->next;
    }

    temp -> next = NULL;
    

    return true;

}

int main()
{
    Node* first  = new Node(1);

    Node* head = first;
    Node* tail = first;

    insertAttail(tail,2);
    insertAttail(tail,3);
    Node * temp1 = tail;
    insertAttail(tail,4);
    insertAttail(tail,5);
   
    insertAttail(tail,6);
    Node* temp = tail;
    insertAttail(tail,7);
    insertAttail(tail,8);
    insertAttail(tail,9);
    tail ->next = temp;


    // countKfromLast(head,2);

    // cout<<detectLoop(head)<<endl;

    traverse(head);

    cout<<deleteLoop(head)<<endl;

    traverse(head);


    return 0;


}