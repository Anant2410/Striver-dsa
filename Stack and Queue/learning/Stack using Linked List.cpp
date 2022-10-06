void MyStack ::push(int x) 
{
    StackNode* temp = new StackNode(x);
    if(temp==NULL)
    {
        return;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    int x = -1;
    StackNode* temp ;
    if(top==NULL) return -1;
    
    else
    {
        temp = top;
        top =  top->next;
        x = temp->data;
        delete(temp);
    }
    return x;
}
