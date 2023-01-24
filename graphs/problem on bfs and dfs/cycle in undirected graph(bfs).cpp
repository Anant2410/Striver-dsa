
class Solution {
  public:
    bool bfs(int src, vector<int> adj[], int vis[])
    {
        vis[src]=1;      //mark node as visited//
        queue<pair<int,int>> q;  
        q.push({src,-1});    //push src with -1//
        while(!q.empty())    
        {
            int node = q.front().first;   // take out node
            int parent = q.front().second; //along with parent
            q.pop();               
            for(auto it: adj[node])  //traverse adjnode
            {
                if(!vis[it])    //if not visited mark them and push to queue
                {
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(parent != it) //else if parent != adjnode cycle is detected
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};       //vis array//
        for(int i=0;i<V;i++) 
        {
            if(!vis[i])       //if not visited call bfs //
            {
                if(bfs(i,adj,vis)) return true;
            }
        }
        return false;
    }
};
