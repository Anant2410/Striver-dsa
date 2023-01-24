void dfs(int node, vector<int> adj[], vector<int>& ans, int vis[])
    {
        vis[node] = 1;
        ans.push_back(node);
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,ans,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vector<int> ans;
        dfs(0,adj,ans,vis);
        return ans;
    }
