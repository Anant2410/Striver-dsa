/* recurrence relation is 
f(n) = f(n-1) + f(n-2)*/

//recurrence relation
int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        
        return fib(n-1) + fib(n-2);
    }

//memoization
int fib(int n) {
        vector<int> dp(n+1,-1);
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = fib(n-1) + fib(n-2);
    }

//tabulation 
vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];

//space optimization
int fib(int n) {
        if(n<=1) return n;
        int prev2 = 0;
        int prev = 1;
        for(int i=2;i<=n;i++)
        {
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
