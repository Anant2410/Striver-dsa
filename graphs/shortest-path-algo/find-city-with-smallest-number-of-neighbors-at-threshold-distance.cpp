/*just apply floyd warshall and find the largest city number*/

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        //create a adjmatrix
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        //their self distance is 0
        for(int i=0;i<n;i++) dist[i][i] = 0;
        // floydd logic
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        //set cityno. to the maximum
        int cityno = n;
        //for storing the city
        int city=0;
        //traverse every city and count the smallest distance
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j = 0;j<n;j++)
            {
                if(dist[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= cityno)
            {
                cityno = cnt;
                city = i;
            }
        }
        return city;
    }
