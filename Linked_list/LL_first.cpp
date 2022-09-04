#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int data;

    Node* next;

    // Constructor
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
    

};

void traverse(Node* &head)
{
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
        return;
    }
    Node* temp = head;

    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
void insertHead(Node* &head,int d)
{
    //step 1: create new node
        Node* newNode = new Node(d);
        //step2: set next ptr to head node
        newNode->next = head;
        //step3: head update;
        head = newNode;
}

void insertAtTail(Node* &tail, int d)
{
    Node* newNode = new Node(d);

    tail->next= newNode;
    tail = newNode;

}
int getlen(Node* &head)
{
    Node* temp = head;
    int len = 0;
    while (temp!=NULL)
    {
        len++;
        temp= temp->next;
    }
    return len;
    
}
void insertAtPosition(Node* &head, Node* &tail,int pos, int d)
{
    int len = getlen(head);
    cout<<"length of LL "<<len<<endl;
    if(pos == 1)
    {
        insertHead(head,d);
    }
    else
    {

        // step 1: Creation of new node
        Node* newNode = new Node(d);

        // step 2: traverse
        Node* prev = head;
        int t = pos - 2;
        while(t--)
        {
            prev = prev->next;
        }

        

        newNode->next= prev->next;
        prev->next=newNode;
        

        if(pos == len+1)
        {
            cout<<"Inside this condn"<<endl;
            tail = newNode;
        }


    }
}


Node* reverse(Node* &head)
{
    if(head == NULL)
        return NULL;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL)
    {
        Node* forword = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = forword;
    }

    return prev;
}

Node* reverseRec(Node* &curr, Node* prev)
{
    if(curr == NULL)
        return prev;

    Node* next = curr ->next;
    curr->next = prev;

    return reverseRec(next, curr);
}
int main()
{
 
    Node *first = new Node(12);
    
    Node *head = first;

    insertHead(head,10);
    insertHead(head,9);
    insertHead(head,8);
    insertHead(head,7);
    insertHead(head,6);

    // traverse(head);
    // cout<<endl;
    // Node* tail= first;
    // insertAtTail(tail,14);

    // insertAtPosition(head,tail,3,100);
    // insertAtPosition(head,tail,4,200);

    // insertAtTail(tail,500);
    // traverse(head);
    // cout<<endl;
    traverse(head);
    cout<<endl; 
    head = reverseRec(head,NULL);
    cout<<"reverse List "<<endl;
    traverse(head);



    return 0;
}