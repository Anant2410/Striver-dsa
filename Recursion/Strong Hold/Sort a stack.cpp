void  insert(stack<int>& s, int x)
{
    if(s.empty() || s.top()<x)
    {
        s.push(x);
        return;
    }
    int x2 = s.top();
    s.pop();
    insert(s,x);
    s.push(x2);
}
void SortedStack :: sort()
{
   if(s.empty())
   {
       return ;
   }
   int x = s.top();
   s.pop();
   sort();
   insert(s,x);
}



// iterative method//
void SortedStack :: sort()
{
   priority_queue<int> pq;
   while(!s.empty()){
       pq.push(-s.top());
       s.pop();
   }
   while(!pq.empty()){
       s.push(-pq.top());
       pq.pop();
   }
   
}
