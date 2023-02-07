/* here concept is pick and non pick*/

///recurrence relation
int f(int i, int *arr)
	{
	    if(i==0) return arr[0];
	    if(i<0) return 0;
	    int notpick = 0 + f(i-1,arr);
	    int pick =  arr[i] + f(i-2,arr);
	    return max(pick,notpick);
	}

//memoization
int f(int i, int *arr, vector<int>& dp)
	{
	    if(i==0) return arr[0];
	    if(i<0) return 0;
	    if(dp[i] != -1) return dp[i];
	    
	    int notpick = 0 + f(i-1,arr,dp);
	    int pick =  arr[i] + f(i-2,arr,dp);
	    
	    return dp[i] = max(pick,notpick);
	}

//tabulation
int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,-1);
	    dp[0] = arr[0];
	    for(int i=1;i<n;i++)
	    {
	       int np = 0 + dp[i-1];
	       int p = arr[i];
	       if(i>1)
	       {
	           p += dp[i-2];
	       }
	       dp[i] = max(p,np);
	    }
	    return dp[n-1];
	}

//space optimization
int prev = arr[0];
        int prev2 = -1;
        for(int i=1;i<n;i++)
        {
            int pick = arr[i];
            if(i>1)
            {
                pick += prev2;
            }
            int notpick = 0 + prev;
            
            int curi = max(pick,notpick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
