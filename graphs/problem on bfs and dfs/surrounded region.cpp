/*take a visited array
now traverse the boundary and check wheather any O 
if so appll logic of dfs*/


//dfs logic
void dfs(int row,int col, vector<vector<int>>& vis, vector<vector<char>>& mat,
    int delrow[], int delcol[] , int n, int m)
    {
        vis[row][col] = 1;
        
        for(int i=0;i<4;i++)
        {
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc] =='O')
            {
                dfs(nr,nc,vis,mat,delrow,delcol,n,m);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        
        vector<vector<int>>vis(n, vector<int>(m,0));
        
        for(int j=0;j<m;j++)            
        {
            if(!vis[0][j] && mat[0][j] =='O')  //first row
            {
                dfs(0,j,vis,mat,delrow,delcol,n,m);
            }
            if(!vis[n-1][j] && mat[n-1][j] =='O')  //last row
            {
                dfs(n-1,j,vis,mat,delrow,delcol,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && mat[i][0] =='O')        //1 col
            {
                dfs(i,0,vis,mat,delrow,delcol,n,m);
            }
            if(!vis[i][m-1] && mat[i][m-1] == 'O')  //last col
            {
                dfs(i,m-1,vis,mat,delrow,delcol,n,m);
            }
        }
       // mark the inner O with the X 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
    }
