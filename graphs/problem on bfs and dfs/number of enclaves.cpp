/* declare a vis array
now traverse boundary and check whether there is 1(land)
if so apply the dfs logic
at the end count the 1 present between the grid*/


int n,m;
  //dfs logic
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid)
    {
        vis[i][j] = 1;
        int ro[] = {0,-1,0,1};
        int co[] = {-1,0,1,0};
        for(int ii=0;ii<4;ii++){
            int r = i + ro[ii];
            int c = j + co[ii];
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]){
                dfs(r,c,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
      //visited array
        vector<vector<int>> vis(n,vector<int>(m,0)); 
        // first and last row
        for(int i=0;i<m;i++){
            if(grid[0][i] && !vis[0][i]){
                dfs(0,i,vis,grid);
            }
            if(grid[n-1][i] && !vis[n-1][i]){
                dfs(n-1,i,vis,grid);
            }
        }
        // first and last coloum
        for(int i=0;i<n;i++){
            if(grid[i][0] && !vis[i][0]){
                dfs(i,0,vis,grid);
            }
            if(grid[i][m-1] && !vis[i][m-1]){
                dfs(i,m-1,vis,grid);
            }
        }
        int ans=0;
      //count number of 1 present between the matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]) ans+=1;
            }
        }
      //return the count of the element 
        return ans;
    }
