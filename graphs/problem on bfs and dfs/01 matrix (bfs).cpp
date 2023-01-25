/*take a dist and vis array
take a queue<row,col,dist>
traverse in given matrix and check
if element is 0 then push to queue with r,c,and 0 and mark them as vis
take out front element and mark it in distance array
and check in all 4 direction whether there is any element that is not
visited and marked as 1 if so then increase the distance*/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));  // distance array
        vector<vector<int>> vis(n, vector<int>(m,0)); //vis array//
        queue<pair<pair<int,int>,int>>q; //queue<row,col,vis>//
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)  //if 0 then push to queue and mark visited//
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty())
        {
          //take out top element and mark in distance array
            int r = q.front().first.first; 
            int c = q.front().first.second;
            int dist = q.front().second;        
            q.pop();
            ans[r][c] = dist;
            for(int i=0;i<4;i++) //traverse in all 4 direction
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc] == 1) //check all constraints
                {
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},dist+1});
                }
            }
        }
        return ans;  //return distance array
    }
