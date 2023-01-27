/* create color array
now traverse for all components and check wheather color of any component is -1 or not
if so apply dfs logic*/

bool check(int node, int col, int n, vector<int>& color, vector<vector<int>>& adj)
    {
        //mark the color array with desired color
        color[node] = col;
        //traverse the adjnode and check
        for(auto it: adj[node])
        {
            if(color[it]==-1)
            {
                if(check(it,!col,n,color,adj)==false) return false;
            }
            else if(col == color[it]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //color array
        vector<int> color(n,-1);  
        //traverse all the components
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(check(i,0,n,color,graph)==false) return false;
            }
        }
        return true;
    }
