/*apply dijkshtra and find shortest path 
if already the shortest path increase the ways in ways array*/

int countPaths(int n, vector<vector<int>>& roads) {
        /creating adjlist
        vector<pair<int,int>> adj[n];
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        //for storing ways and shortest distance
        vector<int> ways(n,0), dist(n,1e9);
        dist[0] = 0;
        ways[0] = 1;
        //{dist,node}
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node])
            {
                int adjnode = it.first;
                int wt = it.second;
                //we reach node for the first time
                if(dist[adjnode] > distance + wt)
                {
                    dist[adjnode] = distance + wt;
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode] = ways[node];
                }
                //if shortest path increase the ways count
                else if(dist[adjnode] == distance + wt)
                {
                    ways[adjnode] += ways[node];
                }
            }
        }
        return ways[n-1]%(1000000007);
    }
