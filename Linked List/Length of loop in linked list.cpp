int countNodesinLoop(struct Node *head)
{
    Node* slow = head;
    Node* fast = head;
    bool flag = false;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
           flag = true;
           break;
        }
    }
    int c = 1;
    if(flag)
    {
        fast = fast->next;
        while(fast!=slow)
        {
            fast = fast->next;
            c++;
        }
        return c;
    }
    return 0;
}
