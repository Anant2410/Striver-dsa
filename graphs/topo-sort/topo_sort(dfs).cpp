/*take a vis array and initialize with 0
now traverse till the components and check if(!vis) call dfs
apply dfs logic and at the end move to stack*/


	void dfs(int node, vector<int>adj[], vector<int>vis,stack<int> st)
	{
    //dfs logic
	    vis[node] = 1;
	    for(auto it: adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<int> vis(V,0);
	  //component logic 
    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,adj,vis,st);
	        }
	    }
	    vector<int> ans;
    //moving elements to vector
	    while(!st.empty())
	    {
	        int temp = st.top();
	        st.pop();
	        ans.push_back(temp);
	    }
	    return ans;
	}
