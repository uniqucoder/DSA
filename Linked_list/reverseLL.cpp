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

Node* reverseLL(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL)
    {
        Node* forward = curr ->next;
        curr -> next = prev;

        prev = curr;
        curr = forward;
    }

    return prev; 
   
}


Node* reverseRec(Node* &curr, Node* prev)
{
    // base case
    if(curr == NULL)
    {
        return prev;
    }

    
    Node* forward = curr ->next;
    curr -> next = prev;

    return reverseRec(forward,curr);

}

Node* getMiddle(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow ->next;

        fast = fast ->next ->next;
    }

    return slow;
}


bool isCircular(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp ->next == head)
        {
            return true;
        }
        temp = temp -> next;
    }

    return false;

}


// revesre nodes in size of k

Node* reverseInK(Node* &head, int k)
{

    // empty list
    if(head == NULL)
    {
        return NULL;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count=0;

    while(curr !=NULL && count < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr= next;
        count++;
    }

    if(next != NULL)
    {
        head -> next = reverseInK(next,k);
    }

    return prev;
}

int getLen(Node* &head)
{
    Node* temp = head;

    int len =0;
    while(temp != NULL)
    {
        len++;
        temp = temp ->next;
    }
    return len;
}

bool palindromeLL(Node* &head)
{
   int len = getLen(head);
   Node* slow = head;
   Node* fast = head;
   Node* prev = NULL;
  
   while(fast != NULL && fast -> next != NULL)
   {
        prev = slow;
        slow = slow -> next;

        fast = fast -> next ->next;
   }

    if(len %2 == 1)
    {
        slow=slow->next;
    }
    
    prev -> next = NULL;
    Node* first = head;
    Node* head2 = reverseLL(slow);

    Node* second =head2;

    
    while(first != NULL)
    {
        if(first ->data != second ->data)
        {
            return false;
        }
        first = first -> next;
        second = second -> next;
    }

    if(first == NULL && second == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }



}

int main()
{
    Node* first = new Node(1);
    Node* head = first;
    Node* tail = first;
    // insertAttail(tail, 2);
    // insertAttail(tail, 2);  

    // insertAttail(tail, 2);

    // insertAttail(tail, 1);
    // insertAttail(tail, 4);
    // insertAttail(tail, 5);
    // insertAttail(tail, 6);
    // insertAttail(tail, 7);
    // insertAttail(tail, 8);


    // traverse(head);
    // cout<<endl;
    // head = reverseRec(head, NULL);

    // traverse(head);

    // cout<<endl;  

    // Node* middle = getMiddle(head);

    // cout<<"Middle Ele is " << middle->data<<endl;  
    // tail -> next = head;
    // cout<<"Linked list is circular "<<isCircular(head)<<endl;




    // Reveser in K size
    traverse(head);
    // cout<<endl;
    // head = reverseInK(head,3);

    // traverse(head);

    if(palindromeLL(head))
    {
        cout<<"LL Is palindrom"<<endl;
    }
    else
    {
        cout<<"LL is not palindrome"<<endl;
    }

    return 0;


}