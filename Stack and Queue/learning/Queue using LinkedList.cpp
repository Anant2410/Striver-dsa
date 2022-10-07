void MyQueue:: push(int x)
{
    QueueNode* temp = new QueueNode(x);
    if(front==NULL)
    {
        rear = temp;
        front = temp;
    }
    
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        if(front==NULL) return -1;
        else
        {
            int x = front->data;
            QueueNode* temp = front;
            front  = front->next;
            delete(temp);
            return x;
        }
}
