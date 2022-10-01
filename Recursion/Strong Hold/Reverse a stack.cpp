void insert(stack<int>& st, int num)
    {
        if(st.empty())
        {
            st.push(num);
            return;
        }
        int x = st.top();
        st.pop();
        insert(st,num);
        st.push(x);
        return;
    }
    void rec(stack<int>& st)
    {
        if(st.size()==1)
        {
            return;
        }
        int num = st.top();
        st.pop();
        rec(st);
        insert(st,num);
    }
    stack<int> Reverse(stack<int> st){
        rec(st);
        return st;
    }
