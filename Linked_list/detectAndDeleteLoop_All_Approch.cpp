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




// Approch one using hash map

Node* detectLoop1(Node* &head)
{
    unordered_map<Node*,bool> m;

    Node* temp = head;

    while(temp != NULL && temp -> next != NULL)
    {
        if(m[temp->next] == false )
        {
            m[temp ->next ]= true;
        }
        else
        {
            cout<<"Loop detected "<<endl;
            return temp;
        }
    }

    return NULL;
}



Node* deleteLoop(Node* & head)
{
    //edge case
    if(head == NULL)
    {
        return NULL;
    }

    Node * fast = detectLoop1(head);

    Node* slow = head;


    while(slow == fast)
    {
        slow = slow -> next;

        fast = fast -> next;

       
    }

    Node * beginning = slow;

    Node* temp = beginning;

    Node* slow = head;
    while(temp != NULL && temp -> next != NULL )
    {
            slow = slow -> next;


            fast = fast -> fast;
    }



    Node* beginning = NULL;
    {
        
    }
}

int main()
{
    Node* first  = new Node(1);

    Node* head = first;
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
    tail ->next = temp;

    cout<<detectLoop1(head);

    return 0;

}