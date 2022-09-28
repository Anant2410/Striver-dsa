priority_queue<int,vector<int>,greater<int>>pq;
     Node *temp = *head;
     while(temp != NULL)
     {
         pq.push(temp->data);
         temp = temp->next;
     }
     temp = *head;
     while(pq.empty()== false)
     {
         temp->data = pq.top();
         pq.pop();
         temp = temp->next;
     }
