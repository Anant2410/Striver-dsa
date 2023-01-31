/*used to find the shortest path from one node to every other node*/

//we can use priority_queue to remove unnecessary time 
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //distaance array for storing distance
        vector<int> dist(V,INT_MAX);
        //mark sorce as 0
        dist[S] = 0;
        //for node and distance pair
        queue<pair<int,int>>q;
        //push source,0 to queue
        q.push({S,0});
        //while queue is not empty
        while(!q.empty())
        {
            //take out top element from queue
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();
            //traverse adjnode and check the given condition
            //if distance[adjnode] > wt + adjwt
            for(auto it: adj[node])
            {
                int adjnode = it[0];
                int adjwt = it[1];
                if(dist[adjnode] > wt + adjwt)
                {
                    dist[adjnode] = wt+adjwt;
                    q.push({adjnode,wt+adjwt});
                }
            }
        }
        //return the distance array
        return dist;
