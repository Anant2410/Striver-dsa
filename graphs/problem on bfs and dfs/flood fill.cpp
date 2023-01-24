//take vis == image//
//take a queue<row,col> and push sr,sc//
//apply bfs when image[newr][newc]==original && vis[newr][newc] != given color//
//return vis//
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>vis = image; //takeing vis = image//
        queue<pair<int,int>> q; //declare a queue<row,col> and push sr,sc//
        q.push({sr,sc});
        int org = image[sr][sc];  // take initial color//
        vis[sr][sc] = color;
        int dr[] = {-1,0,+1,0};    //for checking 4 d//
        int dc[] = {0,+1,0,-1};
        while(!q.empty())   //bfs
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==org && vis[nr][nc]!=color) //valid condition//
                {
                    q.push({nr,nc});        
                    vis[nr][nc] = color;
                }
            }
        }
        return vis;
    }
};
