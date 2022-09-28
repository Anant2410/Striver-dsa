class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       Node* temp = new Node(x);
       if(head==NULL)
       {
           return temp;
       }
       temp->next = head;
       head = temp;
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       Node* temp= new Node(x);
       if(head==NULL)
       {
           return temp;
       }
       Node* p = head;
       while(p->next!=NULL)
       {
           p = p->next;
       }
       temp->next = NULL;
       p->next = temp;
       return head;
    }
};
