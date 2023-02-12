/*top aur left me move krna hai aur count krna hai base case me*/

int ways(int i, int j, vector<vector<int>>& dp)
    {
        //base case
        if(i==0 && j==0) return 1;
        //out of bound
        if(i<0 || j<0) return 0 ;
        //memoization
        if(dp[i][j] != -1) return dp[i][j];
        int up = ways(i-1,j,dp);
        int left = ways(i,j-1,dp);
        //return sum
        return dp[i][j] =  up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return ways(m-1,n-1,dp);
    }

//tabulation 
/*declare the base case
express all stuff in loops
copy the recurrence and write
*/

int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) dp[i][j] = 1;
                else
                {
                    int left=0,up=0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
  
  //space optimization//
  /* if there is use of prev row and prev col we can space optimize the code as well*/
  //not much to think just apply the logic and you are good  to go//
  vector<int> prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) curr[j] = 1;
                else
                {
                    int up=0,left=0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up+left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
