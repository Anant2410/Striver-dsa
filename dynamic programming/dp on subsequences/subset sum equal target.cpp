/*try out possible ways by pick and non pivk method and if found the answer return true*/

//recursive method//
bool f(int ind, int target, vector<int>& arr)
    {
        if(target == 0) return true;
        if(ind==0) return (arr[0] == target);
        
        bool not_take = f(ind-1,target,arr);
        bool take = false;
        if(target >= arr[ind])
        {
            take = f(ind-1,target-arr[ind], arr);
        }
        return (take || not_take);
    }

//memoization method
bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp)
    {
        if(target == 0) return true;
        if(ind==0) return (arr[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool not_take = f(ind-1,target,arr,dp);
        bool take = false;
        if(target >= arr[ind])
        {
            take = f(ind-1,target-arr[ind], arr,dp);
        }
        return dp[ind][target] =  (take || not_take);
    }

//tabulation
for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];

//space optimization
vector<int> prev(k+1,0), curr(k+1,0);
    
    prev[0] = true;
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            curr[target]= notTaken||taken;
        }
        prev = curr;
    }
    
    return prev[k];
