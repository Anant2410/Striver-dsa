// same as bfs just pass parent in the function// 

bool dfs(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,node,vis,adj)) return true;
            }
            else if(parent != it)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0};
       for(int i=0;i<V;i++)
       {
           if(!vis[i])
           {
               if(dfs(i,-1,vis,adj)) return true;
           }
       }
       return false;
    }
