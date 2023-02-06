/* recurrence relation is 
if(n<=1) return 1;
int left = fun(n-1);
int right = fun(n-2) ;
return left + right;
*/

int mod = 1e9+7;
//memoization
    int fun(int n, vector<int>& dp)
    {
        if(n==0 || n==1) return 1;
        if(dp[n] != -1) return dp[n];
        int left = fun(n-1,dp);
        int right = fun(n-2,dp);
        
        
        return dp[n] = (left + right) % mod;
    }
    int countWays(int n)
    {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
//tabulation
int countWays(int n)
    {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
        return dp[n] % mod;
    }
//space optimization
int countWays(int n)
    {
        int prev2 = 1;
        int prev = 1;
        for(int i=2;i<=n;i++)
        {
            int curr = (prev + prev2) % mod; 
            prev2 = prev;
            prev = curr;
        }
        return prev % mod;
    }
