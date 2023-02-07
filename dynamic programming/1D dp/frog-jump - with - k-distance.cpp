/* recurence relation would be
        for(int it=1;it<=k;it++)
        {
            if(i-it>=0)
            {
                int up = f(i-it,arr,n,k,dp) + abs(arr[i] - arr[i-it]);
                ans = min(ans,up);
            }
        }
*/
//memoization
int f(int i, vector<int>& arr, int n, int k, vector<int>& dp)
    {
        if(i==0) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int it=1;it<=k;it++)
        {
            if(i-it>=0)
            {
                int up = f(i-it,arr,n,k,dp) + abs(arr[i] - arr[i-it]);
                ans = min(ans,up);
            }
        }
        return ans;
    }
//tabulation
int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        for(int i=1;i<n;i++)
        {
            int ans = INT_MAX;
            for(int j=1;j<=k;j++)
            {
                if(i-j>=0)
                {
                    int up = dp[i-j] + abs(height[i] - height[i-j]);
                    ans = min(ans,up);
                }
            }
            dp[i] = ans;
        }
        return dp[n-1];
    }
