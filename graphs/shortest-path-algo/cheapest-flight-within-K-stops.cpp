int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //for creating adjlist 
        vector<pair<int,int>> adj[n];
        for(auto it: flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        //for storing min distance 
        vector<int> dist(n,1e9);
        //queue(stops,node,distance)
        queue<pair<int,pair<int,int>>> q;
        //initial configuration
        q.push({0,{src,0}});
        while(!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int wt = q.front().second.second;
            q.pop();
            //if stops are more than required than continue
            if(stops> k ) continue;
            //traverse adjnode and check the desired condition
            for(auto it: adj[node])
            {
                int adjnode = it.first;
                int adjdist = it.second;
                if(dist[adjnode] > adjdist + wt && stops<=k)
                {
                    dist[adjnode] = adjdist + wt;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        //if dst is not reachabale from source 
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
