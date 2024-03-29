//recursive approach
int f(int i, int j, vector<vector<int>>& grid)
    {
        if(i==0 && j==0 && grid[i][j] == 0) return 1;
        else if(i==0 && j==0 && grid[i][j] == 1) return 0;
        if(i<0 || j<0) return 0;
        if(grid[i][j] == 1) return 0;

        int up = f(i-1,j,grid);
        int down = f(i,j-1,grid);

        return up+down;
    }

//memoization
int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i==0 && j==0 && grid[i][j] == 0) return 1;
        else if(i==0 && j==0 && grid[i][j] == 1) return 0;
        if(i<0 || j<0) return 0;
        if(grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int up = f(i-1,j,grid,dp);
        int down = f(i,j-1,grid,dp);

        return dp[i][j] = (up+down)%2000000000;
    }

//tabulation
vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=0 && j>=0 && grid[i][j] == 1) dp[i][j] = 0;
                else if(i==0 && j==0) dp[i][j] = 1;
                else
                {
                    int up = 0,left=0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = (up+left)%mod;
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
                if(i>=0 && j>=0 && grid[i][j] == 1) curr[j] = 0;
                else if(i==0 && j==0) curr[j] = 1;
                else
                {
                    int up = 0,left=0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = (up+left)%mod;
                }
            }
            prev = curr;
        }
        return prev[n-1];
