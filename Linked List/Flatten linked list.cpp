Node* f(Node* a, Node* b)
{
    Node* res = new Node(0);
    Node* temp = res;
    
    while(a!=NULL && b!=NULL)
    {
        if(a->data <= b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
           temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;  
        }
    }
    if(a!=NULL)
    {
        temp->bottom = a;
    }
    else
    {
        temp->bottom = b;
    }
    return res->bottom;
}
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL)
   {
       return root;
   }
   root->next = flatten(root->next);
   
   root = f(root,root->next);
   
   return root;
}
