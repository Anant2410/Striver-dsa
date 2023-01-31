/*create a min heap so taht minimum diff can be displayed at the top
mark starting node distance as 0 and push to pq<dist,row,col>
if reach end return diff else apply basic logic
*/


 int minimumEffortPath(vector<vector<int>>& heights) {
        //taking rows and col of array
        int n = heights.size();
        int m = heights[0].size();
        //declaring min heap<distance,row,col>
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        //craete disatnce array to store min distance
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        //push starting element to min heap
        pq.push({0,{0,0}});
        //mark distance as 0 
        dist[0][0] = 0;
        //for traversing in up,right,down,left
        int dr[] = {-1,0,1,0};
        int dc[] = {0,+1,0,-1};
        
        while(!pq.empty())
        {
           // store diff,r,c
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1) return diff;
            for(int i=0;i<4;i++)
            {
              //calculate new row,col
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                  //find distance as given in question
                    int update = max(abs(heights[r][c] - heights[nr][nc]) , diff);
                    if(dist[nr][nc] > update)
                    {
                        dist[nr][nc] = update;
                        pq.push({update,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
