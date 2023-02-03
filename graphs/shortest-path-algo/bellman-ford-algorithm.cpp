//relax every edge n-1 times//

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dist(V,1e8);
        
        dist[S] = 0;
        // v*e is time complexzity
        
        for(int i=0;i<V-1;i++)
        {
            for(auto it: edges)
            {
                if(dist[it[0]] + it[2] < dist[it[1]])
                {
                    dist[it[1]] = dist[it[0]] + it[2] ;
                }
            }
        }
        //nth iteration//
        for(auto it: edges)
            {
                if(dist[it[0]] + it[2] < dist[it[1]])
                {
                    return {-1};
                }
            }
        return dist;
    }
