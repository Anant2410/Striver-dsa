int minimumMultiplications(vector<int>& arr, int start, int end) {
        //distance array to find min ways
        vector<int> dist(100000, 1e9);
        //mark start as 0
        dist[start] = 0;
        //queue<node,distance>
        queue<pair<int,int>> q;
        //push node with starting distance
        q.push({start,0});
        while(!q.empty())
        {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            if(node == end) return distance;
            //traverse the end
            for(auto it: arr)
            {
                //multiply node with the element
                int adjnode = (it*node)%100000;
                //if distance is greater edit the distance and push to queue
                if(dist[adjnode] > distance + 1)
                {
                    dist[adjnode] = distance+1;
                    q.push({adjnode,dist[adjnode]});
                }
            }
        }
        return -1;
    }
