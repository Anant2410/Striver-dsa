//bfs
class Solution {
  public:
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
};


//dfs leetcode
class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis)
    {
        vis[node] = 1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};
