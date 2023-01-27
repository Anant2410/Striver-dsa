/*take vis and path vis array and mark all of  them with 0
iterate to te components and check if they are not visited call dfs
in dfs, mark both vis and path vis to 1 and check for adjnode
if not find mark path vis  as 0 and return false*/


bool dfs(int node, int n, vector<int> adj[] , int vis[], int pathvis[])
    {
        // mark both as visited
        vis[node] = 1;
        pathvis[node] = 1;
        //iterate for the adjacent node
        for(auto it: adj[node])
        {
            //same logic
            if(!vis[it])
            {
                if(dfs(it,n,adj,vis,pathvis)) return true;
            }
            else if(pathvis[it] && vis[it])
            {
                return true;
            }
        }
        //on returning mark path vis as 0 and return false as no cycle is detected
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        //declare vis and path vis  array
        int vis[V] = {0};
        int pathvis[V] = {0};
        // iterate for  components logic
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,V,adj,vis,pathvis) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
