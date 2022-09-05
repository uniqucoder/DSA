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