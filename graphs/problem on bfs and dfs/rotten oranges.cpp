// take a queue({row,col},time);
//iterate in matrix and push the r,c if grid[r][c] ==2;
// now apply bfs//
//if vis array has element!=2 return -1;
//return time

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0)); //declare vis array//
        queue<pair<pair<int,int>,int>>q; // queue<row,col,time>;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)      // if rotten push to queue
                {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        int dr[] = {-1,0,1,0};     // for moving up,right,down,left//
        int dc[] = {0,1,0,-1};
        int time = 0;
        while(!q.empty())             // bfs logic
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && vis[nr][nc]==0)
                {
                    q.push({{nr,nc},t+1});
                    vis[nr][nc] = 2;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]!=2 && grid[i][j] == 1) return -1;    //if orange can't be rotten
            }
        } 
        return time;          //actual time to rotten all oranges
    }
};
