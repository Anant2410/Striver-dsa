/*here there is a single fixed point  and other is  a variable point so we start to built the logic of  recurrence relation from the fixed point*/

//recurrence relation
if(i==arr.size()-1) return arr[i][j];

        int d = arr[i][j] + f(i+1,j,arr);
        int dg = arr[i][j] + f(i+1,j+1,arr);

        return min(d,dg);
//memoization
if(i==arr.size()-1) return arr[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int d = arr[i][j] + f(i+1,j,arr,dp);
        int dg = arr[i][j] + f(i+1,j+1,arr,dp);
        return dp[i][j] =  min(d,dg); 

//tabulation
int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int j=0;j<triangle[n-1].size();j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }

//space optimization
int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n,0);
        for(int j=0;j<triangle[n-1].size();j++)
        {
            prev[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            vector<int> curr(n,0);
            for(int j=0;j<triangle[i].size();j++)
            {
                int d = triangle[i][j] + prev[j];
                int dg = triangle[i][j] + prev[j+1];

                curr[j] = min(d,dg);
            }
            prev = curr;
        }
        return prev[0];
    }
