// number o0f provinces question on gfg
void bfs(int src, vector<int> adj[], vector<int>& vis)
    {
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    bfs(it,adj,vis);
                }
            }
        }
        return ;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjlist[V];
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j] && i!=j)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                count++;
                bfs(i,adjlist,vis);
            }
        }
        return count;
    }
