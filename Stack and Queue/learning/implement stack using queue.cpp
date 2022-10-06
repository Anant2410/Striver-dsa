// using single queue // 
class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q;
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            int x = q.front();
            q.pop();
            q.push(x);
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()) return true;
        
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */









////// gfg ///// (using 2 queue)
void QueueStack :: push(int x)
{
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        if(q1.empty()) return -1;
        int x = q1.front();
        q1.pop();
        return x;
}
