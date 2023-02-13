//recursive//
int f(int i, int j, vector<vector<int>>& grid)
    {
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1000;
        int up = grid[i][j] + f(i-1,j,grid);
        int left = grid[i][j] + f(i,j-1,grid);

        return min(up,left);
    }
//memoization
int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1000;
        if(dp[i][j]!= -1) return dp[i][j];
        int up = grid[i][j] + f(i-1,j,grid,dp);
        int left = grid[i][j] + f(i,j-1,grid,dp);

        return dp[i][j] =   min(up,left);
    }
//tabulation
vector<vector<int>> dp(m, vector<int>(n,1000));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) dp[i][j] = grid[0][0];
                else
                {
                    int up=grid[i][j];
                    if(i>0) up +=  dp[i-1][j];
                    else up += 1000;
                    int left = grid[i][j];
                    if(j>0) left += dp[i][j-1];
                    else left += 1000;
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[m-1][n-1];

//space optimization
vector<int> prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) curr[j] = grid[0][0];
                else
                {
                    int up=grid[i][j];
                    if(i>0) up +=  prev[j];
                    else up += 1000;
                    int left = grid[i][j];
                    if(j>0) left += curr[j-1];
                    else left += 1000;
                    curr[j] = min(up,left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
