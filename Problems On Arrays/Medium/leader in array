vector<int> leaders(int arr[], int n){
        stack<int> st;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i] >= st.top())
            {
                st.push(arr[i]);
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
